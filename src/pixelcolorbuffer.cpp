#include "cprocessing.hpp"
#include "color.hpp"
#include "pixelcolorbuffer.hpp"

using namespace cprocessing;

PixelColorBuffer::PixelColorBuffer(char * b) {
	this->b = b;
}

//FIXME:: this should call from b and not backbuffer
color PixelColorBuffer::operator[] (int x) {
	return buffertocolor(backbuffer, x);
}