/*
 * main.cpp
 *
 *  Created on: Sep, 16, 2011
 *      Author: esperanc
 */

#include <cprocessing.hpp>

using namespace cprocessing;

PImage img (100,100);

void setup() {
    size(200,200);
    color c (0,0,255,100);
    int n = img.width*img.height;
    for (int i = 0; i < n; i++) img.pixels[i] = c;
}

void draw() {
	background (200);
	img.put (10,10);
}

