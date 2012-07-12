/*
 * main.cpp
 *
 *  Created on: Jul 19, 2011
 *      Author: claudio
 *
 * Contains a sample main file which inits a window and runs the event loop
 */

#include "cprocessing.hpp"

//#include <Magick++.h>

using namespace cprocessing;
//using namespace Magick;

int main (int argc,char **argv) {
	/*#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
		Magick::InitializeMagick(*argv);	//initialization not required in systems that can support installing to known locations
    #endif */
	srand(time(NULL));
	run();
}
