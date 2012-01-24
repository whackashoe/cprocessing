/*
 * main.cpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#include <cprocessing.hpp>

using namespace cprocessing;

void draw() {
	fill (255);
	ellipseMode(CENTER);
	ellipse(35, 35, 50, 50);
	ellipseMode(CORNER);
	fill(102);
	ellipse(35, 35, 50, 50);
}

