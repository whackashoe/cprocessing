/*
 * main.cpp
 *
 *  Created on: Sep 2, 2011
 *      Author: nilton.gduarte
 */

#include <cprocessing.hpp>

using namespace cprocessing;

void setup () {
    size (100,100);
}

void draw() {
    noStroke();
    colorMode(HSB, 100);
    for (int i = 0; i < 100; i++) {
       for (int j = 0; j < 100; j++) {
          stroke(i, j, 100);
          point(i, j);
       }
    }
}

