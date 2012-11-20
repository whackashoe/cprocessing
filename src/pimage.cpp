/*
 * image.cpp
 *
 *  Created on: Sep 16, 2011
 *      Author: claudio
 *
 *  Image support
 */

#include <GL/glut.h>
#include <cassert>
#include <iostream>
#include "cprocessing.hpp"
#include "pimage.hpp"

using namespace cprocessing;
//using namespace Magick;

namespace cprocessing {


    PImage::PImage() {
        /*this->width = 1;
        this->height = 1;
        this->pixels = new color[1];
        this->type = ARGB;

        Geometry g(1, 1);
        Color c;
        this->img = new Image(g, c);*/
    }
    /// Constructor
    /// @arg width horizontal size
    /// @arg height vertical size
    /// @arg type ARGB, RGB or ALPHA
    PImage::PImage (int width, int height, unsigned type) {
    
        // Simple argument checking
        assert (width>=0 && height>=0 && width < 1e6 && height < 1e6 && 
                (type == ARGB || type == RGB || type == ALPHA));  
                
        this->width = width;
        this->height = height;
        this->pixels = new color[width*height];
        this->type = type;

        //Geometry g(width, height);
        //Color c;
        //this->img = new Image(g, c);
    }
    
    /// Destructor
    PImage::~PImage () {
        delete pixels;
        //delete img;
    }

    
    void PImage::set(int x, int y, const color& c) {
        pixels[(y*width)+x] = c;
    }
    
    
    /// Draws the image at position (x, y) of the screen
    void PImage::put (int x, int y) {
        // invert y coordinate
        if (config&Y_DOWN) y = y + height;

        glPushMatrix();
        glRasterPos2i (x,y);         // set write position
        glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) pixels);
        glPopMatrix();
    }

    /// Draws the image at position (x, y) of the screen
    void PImage::put (int x, int y, int w, int h) {
        // invert y coordinate
        if (config&Y_DOWN) y = y + height;

        glPushMatrix();
        glRasterPos2i (x,y);         // set write position
        glDrawPixels(w, h, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) pixels);
        glPopMatrix();
    }

    void PImage::loadImage(std::string src) {
        /*try {
            img = new Image("poop");
        } catch( Exception &error_ ) {
            std::cout << "Caught exception: " << error_.what() << std::endl;
        }*/
    }
}
