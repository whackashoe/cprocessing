#include "cprocessing.hpp"


PixelColorBuffer::PixelColorBuffer() {
	this->b = 0;
}

void PixelColorBuffer::setBuffer(unsigned char *& b) {
	this->b = &b;
}

color PixelColorBuffer::buffertocolor(int n) {
	color c(0);
	c.rgba[0]=(*b)[(n*4)+0];
	c.rgba[1]=(*b)[(n*4)+1];
	c.rgba[2]=(*b)[(n*4)+2];
	c.rgba[3]=(*b)[(n*4)+3];
	return c;
}

void PixelColorBuffer::colortobuffer(int n, const color& c) {
	(*b)[(n*4)+0] = c.rgba[0];
	(*b)[(n*4)+1] = c.rgba[1];
	(*b)[(n*4)+2] = c.rgba[2];
	(*b)[(n*4)+3] = c.rgba[3];
}

color PixelColorBuffer::operator[] (int x) {
	return this->buffertocolor(x);
}
