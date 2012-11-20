#include <cprocessing/cprocessing.hpp>

using namespace cprocessing;

/*
 * Undrawable rectangle on screen when background not called in draw
 * */




void setup()
{
	size(480,360);
    background(255);
}

void draw()
{
    fill(200);
    rect(frameCount, 0, 50, 50);
    fill(snoise(frameCount/1000.0f)*255);
    rect(mouseX, mouseY, 100, 100);
}
