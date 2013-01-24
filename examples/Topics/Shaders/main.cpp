#include <cprocessing/cprocessing.hpp>

using namespace cprocessing;

//PShader when created before setup is run must be a pointer
//as cprocessing needs to initialize things before it can be run

PShader * s;

void setup()
{
	size(480,360);
    s = new PShader(); //this is how we create a new object from a pointer
	s->setFragmentShader("frag.glsl"); //load the fragment and vertex shaders
	s->setVertexShader("vert.glsl");
	s->bind(); //this is how we finally "bind" the shader to the program so that it can be used
}

void draw()
{
	background(0);
    //notice that this becomes red due to the fragment shader running
    triangle(20, 20, 50, 50, 100, 30);
}
