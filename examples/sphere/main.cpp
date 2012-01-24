#include <cprocessing.hpp>

using namespace cprocessing;

void draw () {
	background(200);
	noStroke();
	directionalLight(128, 128, 128, -1, 0, 0);
	fill(255,255,0);
	translate(100, 150, 0);
	sphere(50);
}

void setup() {
	size (300,300);
}

