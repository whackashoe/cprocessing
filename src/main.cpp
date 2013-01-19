/*
 * main.cpp
 *
 *  Created on: Jul 19, 2011
 *      Author: claudio
 *
 * Contains a sample main file which inits a window and runs the event loop
 */
#include "cprocessing.hpp"

using namespace cprocessing;

int main (int argc,char **argv) {
	srand(time(NULL));
	for(int i=0; i<argc; i++) {
		args.add(std::string(argv[i]));
	}
	run();
}
