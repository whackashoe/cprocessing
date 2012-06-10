/*
 * main.cpp
 *
 *  Created on: Jul 19, 2011
 *      Author: claudio
 *
 * Contains a sample main file which inits a window and runs the event loop
 */

#include "cprocessing.hpp"
#include <Magick++.h>

using namespace cprocessing;
using namespace Magick;

int main (int argc,char **argv) {
    Magick::InitializeMagick(*argv);
	run();
}
