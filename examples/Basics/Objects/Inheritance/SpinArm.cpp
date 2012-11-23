#include <cprocessing/cprocessing.hpp>
#include "SpinArm.hpp"

void SpinArm::display() {
  strokeWeight(1);
  stroke(0);
  pushMatrix();
  translate(x, y);
  angle += speed;
  rotate(angle);
  line(0, 0, 165, 0);
  popMatrix();
}