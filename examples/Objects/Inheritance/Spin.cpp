#include "Spin.hpp"

Spin::Spin(float xpos, float ypos, float s) {
	angle = 0.0;
	x = xpos;
	y = ypos;
	speed = s;
}
void Spin::update() {
	angle += speed;
}