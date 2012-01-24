#include <cprocessing.hpp>

using namespace cprocessing;

void setup(){
	size(230,230);
}

void draw() {

	rectMode(CENTER);
	rect(40,40,50,50);
	rectMode(RADIUS);
	rect(90,90,25,25);
	rectMode(CORNERS);
	rect(115,115,165,165);
	rectMode(CORNER);
	rect(165,165,50,50);
}
