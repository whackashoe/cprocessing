/*
 * image.cpp
 *
 *  Created on: Sep 16, 2011
 *      Author: claudio
 *
 *  Image support
 */

#include <GL/glut.h>
#include <FreeImage.h>
#include <cassert>
#include <iostream>
#include "cprocessing.hpp"
#include "pimage.hpp"

using namespace cprocessing;

namespace cprocessing {


    PImage::PImage() {
        this->width = 0;
        this->height = 0;
        this->type = ARGB;
        this->texturebuffer = 0;
        //this->pixels = new PixelColorBuffer((unsigned char *) texturebuffer);
    }

    PImage::PImage (int width, int height, unsigned type) {
        assert (width>=0 && height>=0 && 
                width < 1e6 && height < 1e6 && 
               (type == ARGB || type == RGB || type == ALPHA));

        this->width = width;
        this->height = height;
        this->type = type;
        this->texturebuffer = 0;
        //this->pixels = new PixelColorBuffer((unsigned char *) texturebuffer);
    }
    
    /// Destructor
    PImage::~PImage () {}

    
    PImage& PImage::get() {
        return (*this);
    }

    color PImage::get(int x, int y) {
        return pixels.buffertocolor((y*w)+x);
    }


    /// Draws the image at position (x, y) of the screen
    void PImage::put (int x, int y, int w, int h) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, w, h, 0, GL_RGBA,GL_UNSIGNED_BYTE,(GLvoid*)texturebuffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glPushMatrix();
        glTranslatef(x, y, 0.0);
        glScalef(w, h, 1.0);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 1.0);
            glVertex3f(0.0, 0.0, 0.0);
            glTexCoord2f(1.0, 1.0);
            glVertex3f(1.0, 0.0, 0.0);
            glTexCoord2f(1.0, 0.0);
            glVertex3f(1.0, 1.0, 0.0);
            glTexCoord2f(0.0, 0.0);
            glVertex3f(0.0, 1.0, 0.0);
        glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }

    void PImage::loadImage(const char * src) {
        format = FreeImage_GetFileType(src,0);
        imagen = FreeImage_Load(format, src);
 
        temp = imagen;
        imagen = FreeImage_ConvertTo32Bits(imagen);
        FreeImage_Unload(temp);
     
        w = FreeImage_GetWidth(imagen);
        h = FreeImage_GetHeight(imagen);
     
        texturebuffer = new GLubyte[4*w*h];
        char * tempbuffer = (char*)FreeImage_GetBits(imagen);

        //FreeImage loads in BGR format, so you need to swap some bytes(Or use GL_BGR).
        for(int j= 0; j<w*h; j++){
            texturebuffer[j*4+0]= tempbuffer[j*4+2];
            texturebuffer[j*4+1]= tempbuffer[j*4+1];
            texturebuffer[j*4+2]= tempbuffer[j*4+0];
            texturebuffer[j*4+3]= tempbuffer[j*4+3];
        }

        glGenTextures(1, &textureID);

        this->pixels.setBuffer(texturebuffer);
    }
}

