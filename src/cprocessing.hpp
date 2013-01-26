/*
 * cprocessing.hpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#ifndef CPROCESSING_HPP_
#define CPROCESSING_HPP_

#include <cmath>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <limits>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif


#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>
#include <GL/glu.h>
#include <FreeImage.h>

#include "init.hpp"
#include "pconstant.hpp"
#include "arraylist.hpp"
#include "string.hpp"
#include "color.hpp"
#include "pixelcolorbuffer.hpp"
#include "pimage.hpp"
#include "pvector.hpp"
#include "snoise.hpp"
#include "pnoise.hpp"
#include "style.hpp"
#include "hashmap.hpp"
#include "pshader.hpp"
#include "pthread.hpp"
#include "pcamera.hpp"
#include "ptime.hpp"
#include "lights.hpp"
#include "random.hpp"
#include "maths.hpp"
#include "primitives.hpp"
#include "attributes.hpp"
#include "shapes.hpp"
#include "transformations.hpp"
#include "io.hpp"
#include "screenpixels.hpp"
#include "lights.hpp"

typedef bool boolean;

namespace cprocessing {
	//============================================================================
	//
	// Global variables (defined in file cprocessing.cpp)
	//
	extern ArrayList<std::string> args;
	extern int mouseX;  		/**< Mouse x coordinate*/
	extern int mouseY;  		/**< Mouse y coordinate*/
	extern int pmouseX; 		/**< Previous mouse x coordinate*/
	extern int pmouseY; 		/**< Previous mouse y coordinate*/
	extern bool mousePressed; 	/**< Whether any mouse button is pressed*/
	extern int mouseButton; 	/**< Which button is pressed*/
	extern bool keyPressed; 	/**< Whether a key was pressed*/
	extern unsigned char key; 	/**< Which (ASCII) key was pressed*/
	extern int keyCode; 		/**< Code for the last pressed key*/
	extern int width;		 	/**< window width*/
	extern int height; 			/**< window height*/
	extern int screenWidth;		/**< window width*/
	extern int screenHeight; 	/**< window height*/
	extern unsigned config; 	/**< configuration flags*/
	extern int framerate; 		/**< Frames per second*/
	extern double framedelay;	/**< Delay in seconds between frame*/
    extern int frameCount; 		/**< frames since start*/
	extern std::vector<Style> styles; /**< Stack of styles*/
	extern PixelColorBuffer pixels; /**< virtual array of pixels to get and put from (operated thru backbuffer) */
	extern PImage screenBuffer; // ^^
	extern bool looping;    	/**< true makes display call itself*/
	extern bool redrawflag;		//to draw next frame immediately
	extern int initialized; 	//glfw initialized yet
  
	
	void redraw();

    /// Sets up a window of the given size
    /// @param w Desired window width in pixels.
    /// @param h Desired window height in pixels.
    /// @param name Desired window title.

    void size (unsigned w, unsigned h, const char* name = "cprocessing");

    //// Initializes and runs the application main event loop
    void run();
}

#endif
