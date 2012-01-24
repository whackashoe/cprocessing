/*
 * main.cpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#include <cprocessing.hpp>
#include <ctime>
#include <vector>
using namespace cprocessing;

clock_t clock0;

class Annotation {
public:
	clock_t timestamp;
	int x0, y0, x1, y1; 
	Annotation (int x0, int y0, int x1, int y1, clock_t t) {
		this->x0 = x0;
		this->y0 = y0;
		this->x1 = x1;
		this->y1 = y1;
		this->timestamp = t - clock0;
	}
	void draw () {
		line (x0, y0, x1, y1);
	}
};

// All annotations
std::vector<Annotation> annotation;

void mouseDragged () {
	annotation.push_back (Annotation(pmouseX, pmouseY, mouseX, mouseY, clock()));
}

void keyPressed () {
	clock0 = clock();
}

void draw() {
	background(200);
	for (int i = 0; i < annotation.size(); i++) {
		if (annotation[i].timestamp < clock()-clock0) {
  		    annotation[i].draw();
  		}
	}
}

void setup () {
	size (400, 400);
	clock0 = clock();
}
	
