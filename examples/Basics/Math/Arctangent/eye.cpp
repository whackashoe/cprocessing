#include <cprocessing/cprocessing.hpp>
#include "eye.hpp"

Eye::Eye(int tx, int ty, int ts) {
    angle = 0.0;
    x = tx;
    y = ty;
    size = ts;
}

void Eye::update(int mx, int my) {
  angle = atan2(my-y, mx-x);
}

void Eye::display() {
  pushMatrix();
  translate(x, y);
  fill(255);
  ellipse(0, 0, size, size);
  rotate(angle);
  fill(153, 204, 0);
  ellipse(size/4, 0, size/2, size/2);
  popMatrix();
}