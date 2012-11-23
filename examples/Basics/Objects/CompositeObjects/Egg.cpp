#include <cprocessing/cprocessing.hpp>
#include "Egg.hpp"

Egg::Egg(float xpos, float ypos, float t, float s) {
  x = xpos;
  y = ypos;
  tilt = t;
  scalar = s / 100.0;
}

void Egg::wobble() {
  tilt = cos(angle) / 8;
  angle += 0.1;
}

void Egg::display() {
  noStroke();
  fill(255);
  pushMatrix();
  translate(x, y);
  rotate(tilt);
  scale(scalar);
  beginShape();
  vertex(0, -100);
  bezierVertex(25, -100, 40, -65, 40, -40);
  bezierVertex(40, -15, 25, 0, 0, 0);
  bezierVertex(-25, 0, -40, -15, -40, -40);
  bezierVertex(-40, -65, -25, -100, 0, -100);
  endShape();
  popMatrix();
}