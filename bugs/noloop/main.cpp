#include <cprocessing/cprocessing.hpp>

using namespace cprocessing;

/*
 * Nothing gets drawn in this scenario
 * */


void setup()
{
	size(480,360);
    background(0);
    fill(100, 0, 0);
    rect(30, 30, 50, 50);
    noLoop();
}
