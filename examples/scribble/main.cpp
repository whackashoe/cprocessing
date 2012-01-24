/*
 * main.cpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#include <cprocessing.hpp>

using namespace cprocessing;

void mouseDragged() {
	line (pmouseX, pmouseY, mouseX, mouseY);
}

void keyPressed() {
	beginShape();
	vertex (10, 10);
	bezierVertex (10, 100,100, 10, 100, 100 );
	endShape();
}

void draw() {
}

void setup() {
	size (300,300);
	smooth();
	strokeWeight(1);
	//config &= ~BACK_BUFFER;
}


