#include <cprocessing/cprocessing.hpp>
#include "Ring.hpp"

Ring::Ring() {
  on = false;
}

void Ring::start(float xpos, float ypos) {
  x = xpos;
  y = ypos;
  on = true;
  diameter = 1;
}

void Ring::grow() {
  if (on == true) {
    diameter += 0.5;
    if (diameter > width*2) {
      diameter = 0.0;
    }
  }
}

void Ring::display() {
  if (on == true) {
    noFill();
    strokeWeight(4);
    stroke(155, 153);
    ellipse(x, y, diameter, diameter);
  }
}