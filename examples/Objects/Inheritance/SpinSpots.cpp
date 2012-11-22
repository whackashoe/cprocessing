#include <cprocessing/cprocessing.hpp>
#include "SpinSpots.hpp"

void SpinSpots::display() {
  noStroke();
  pushMatrix();
  translate(x, y);
  angle += speed;
  rotate(angle);
  ellipse(-dim/2, 0, dim, dim);
  ellipse(dim/2, 0, dim, dim);
  popMatrix();
}