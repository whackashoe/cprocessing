/*
 * graphics.cpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#include <GL/glut.h>
#include <iostream>
#include <cassert>
#include "cprocessing.hpp"

/// This will link with the client's functions
extern void draw();
extern void setup();
extern void mousePressed();
extern void mouseReleased();
extern void mouseMoved();
extern void mouseDragged();
extern void keyPressed();
extern void keyReleased();

using namespace cprocessing;

bool mouseRecordFlag = true; // When to record or not the mouse position
/// Variables and functions to maintain a backup buffer
char * backbuffer = 0;

static void allocbuffer() {
	if (backbuffer != 0) delete backbuffer;
	backbuffer = new char [width*height*4]; 
}

static void readbuffer() {
	if (backbuffer) {
		glFlush();
		glReadPixels (0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE , (void*) backbuffer);
	}
}

static void writebuffer() {
	if (backbuffer) {
		glPushMatrix();
		glLoadIdentity();
		glRasterPos3f(0,0,0);
		glDrawPixels (width, height, GL_RGBA, GL_UNSIGNED_BYTE , (void*) backbuffer);
		glPopMatrix();
	}
}

namespace cprocessing {

	//
    // Global variables
	//

	int mouseX = 0;  ///< Mouse x coordinate
	int mouseY = 0;  ///< Mouse y coordinate
	int pmouseX = 0;  ///< Previous mouse x coordinate
	int pmouseY = 0;  ///< Previous mouse y coordinate
	bool mousePressed = false; ///< Whether any mouse button is pressed
	int mouseButton = LEFT; ///< Which button is pressed
	bool keyPressed = false; ///< Whether a key was pressed
	unsigned char key; ///< Which (ASCII) key was pressed
	int keyCode;   ///< Code for the last pressed key

	int width;     ///< window width
	int height;    ///< window height

	unsigned config = HALF_PIXEL_SHIFT | Y_DOWN | BACK_BUFFER; ///< Configuration flags

	int frameRate = 60; ///< Frames per second

	int initialized = false; 	///< Whether or not initialization of glut took place

	color strokeColor (0,0,0);     ///< Line drawing color
	color fillColor   (255,255,255);   ///< Area drawing color


	/// 
	/// Global OpenGL initialization code. Should be called at least once when screen is established
	///
    static void init () {
    
    	// Enable depth buffer
    	glEnable(GL_DEPTH_TEST);
    	
    	// Make it possible to overwrite pixels
        glDepthFunc(GL_LEQUAL);
        
        // Helps when drawing in 3D with wireframe superimposed on the filled faces
        glPolygonOffset (1., -1.);
        
        // Cope with scaling transformations
        glEnable(GL_RESCALE_NORMAL);
        
        // Disable the default additional ambient component
        float ambient [] = {0, 0, 0, 1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
 
		// By default, y is flipped, so front is clockwise
		glFrontFace(GL_CW);

    	// Make it possible to set material properties by using glcolor
	    glEnable(GL_COLOR_MATERIAL);
	    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    	glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
	}    	


    /// This is called for each frame
    static void display () {

		// Restore backing buffer if needed
		if (config&BACK_BUFFER) writebuffer();
        
        // Restore default state
        camera();
        perspective();
        noLights();

        // Call external display function
        ::draw();
        mouseRecordFlag = true;

		// Refresh backing buffer if needed
		if (config&BACK_BUFFER) readbuffer();

        // End by swapping front and back buffers
        glutSwapBuffers() ;
    }

    /// Called whenever window geometry is changed.
    /// @param wid New width of the window.
    /// @param hgt New height of the window.
    static void reshape (int wid, int hgt)
    {
        glViewport(0,0,wid,hgt);

        width = wid;
        height = hgt;

        // Default background is gray 70%
        background (200);
        
        // Initialize OPENGL modes
        init();
        
        // Reset backup buffer if needed
        if (config&BACK_BUFFER) {
        	allocbuffer();
        	readbuffer();
        }
       
    }

    /// The refresh function is called periodically to redisplay
    static void refresh (int) {
    	glutPostRedisplay();
    	glutTimerFunc (1000/frameRate, refresh, 0);
    }

    /// Called whenever mouse moves
    static void mousemotion (int x, int y) {
      if (mouseRecordFlag){
         pmouseX = mouseX;
         pmouseY = mouseY;
         mouseX = x;
         mouseY = y;
         mouseRecordFlag = false;
      }
      ::mouseMoved();
    	if (mousePressed) {
    		::mouseDragged();
    	}
    }

    /// Called whenever mouse button is pressed
    static void mouse (int button, int state, int x, int y) {
       if (mouseRecordFlag){
         pmouseX = mouseX;
         pmouseY = mouseY;
         mouseX = x;
         mouseY = y;
         mouseRecordFlag = false;
       }

       mousePressed = state == GLUT_DOWN;
  
       if (button == GLUT_LEFT_BUTTON) {
          mouseButton = LEFT;
       } else if (button == GLUT_RIGHT_BUTTON) {
          mouseButton = RIGHT;
       } else {
          mouseButton = CENTER;
       }
       if (mousePressed) {
          ::mousePressed();
       }
       else {
          ::mouseReleased();
       }
    }

    /// Called whenever a key is pressed
    static void keyboard (unsigned char ch, int x, int y) {
    	keyPressed = true;
    	key = ch;
    	keyCode = ch;
    	::keyPressed();
    }

    /// Called whenever a key is released
    static void keyboardup (unsigned char ch, int x, int y) {
    	keyPressed = false;
    	::keyReleased();
    }

    /// Called whenever a special key is pressed
    static void special (int ch, int x, int y) {
    	keyPressed = true;
    	key = CODED;
    	keyCode = 0;
    	switch (ch) {
			case GLUT_KEY_F1:
			case GLUT_KEY_F2:
			case GLUT_KEY_F3:
			case GLUT_KEY_F4:
			case GLUT_KEY_F5:
			case GLUT_KEY_F6:
			case GLUT_KEY_F7:
			case GLUT_KEY_F8:
			case GLUT_KEY_F9:
			case GLUT_KEY_F10:
			case GLUT_KEY_F11:
			case GLUT_KEY_F12:
				keyCode = ch + F1 - GLUT_KEY_F1;
				break;
			case GLUT_KEY_LEFT:
				keyCode = LEFT;
				break;
			case GLUT_KEY_UP:
				keyCode = UP;
				break;
			case GLUT_KEY_RIGHT:
				keyCode = RIGHT;
				break;
			case GLUT_KEY_DOWN:
				keyCode = DOWN;
				break;
			case GLUT_KEY_PAGE_UP:
				keyCode = PAGEUP;
				break;
			case GLUT_KEY_PAGE_DOWN:
				keyCode = PAGEDOWN;
				break;
			case GLUT_KEY_HOME:
				keyCode = HOME;
				break;
			case GLUT_KEY_END:
				keyCode = END;
				break;
			case GLUT_KEY_INSERT:
				keyCode = INSERT;
				break;
    	}
    	::keyPressed();
    }


    /// Called whenever a special key is released
    static void specialup (int ch, int x, int y) {
		// Restore backing buffer if needed
		if (config&BACK_BUFFER) writebuffer();

    	keyPressed = false;
    	::keyReleased();

		// Refresh backing buffer if needed
		if (config&BACK_BUFFER) readbuffer();
    }

    /// Sets up a window of the given size
    /// @param wid Desired window width in pixels.
    /// @param hgt Desired window height in pixels.
    /// @param name Desired window title.
    void size (unsigned wid, unsigned hgt, const char* name) {
    	if (initialized) {
    		glutReshapeWindow (wid, hgt);
    		glutSetWindowTitle (name);
    	} else {
			glutInitWindowSize (wid, hgt);
			width = wid;
			height = hgt;
			glutCreateWindow (name);
			glutReshapeFunc(reshape);
			glutDisplayFunc(display);
			glutMotionFunc (mousemotion);
			glutPassiveMotionFunc (mousemotion);
			glutMouseFunc (mouse);
			glutKeyboardFunc (keyboard);
			glutKeyboardUpFunc (keyboardup);
			glutSpecialFunc(special);
			glutSpecialUpFunc(specialup);
			initialized = true;
    	}

    }
    
    /// Initializes and runs the application main event loop
    void run() {
		int argc = 0;
		char **argv = 0;
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    	glutTimerFunc (1000/frameRate, refresh, 0);
    	bezierDetail(50);
    	ellipseDetail(50);
    	sphereDetail(30,30);
    	::setup();
        glutMainLoop();
    }
}

