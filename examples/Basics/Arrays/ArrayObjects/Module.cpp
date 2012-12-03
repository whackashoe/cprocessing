#include <cprocessing/cprocessing.hpp>
#include "Module.hpp"

// Contructor
Module::Module() {
  xDirection = 1;
  yDirection = 1;
}
Module::Module(int xOffsetTemp, int yOffsetTemp, int xTemp, int yTemp, float speedTemp, int tempUnit) {
  xOffset = xOffsetTemp;
  yOffset = yOffsetTemp;
  x = xTemp;
  y = yTemp;
  speed = speedTemp;
  unit = tempUnit;
  xDirection = 1;
  yDirection = 1;
}
  
  // Custom method for updating the variables
void Module::update() {
  x = x + (speed * xDirection);
  if (x >= unit || x <= 0) {
    xDirection *= -1;
    x = x + (1 * xDirection);
    y = y + (1 * yDirection);
  }
  if (y >= unit || y <= 0) {
    yDirection *= -1;
    y = y + (1 * yDirection);
  }
}
  
  // Custom method for drawing the object
void Module::draw() {
  fill(255);
  ellipse(xOffset + x, yOffset + y, 6, 6);
}
