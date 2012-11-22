#include <cprocessing/cprocessing.hpp>
#include "SpinArm.hpp"
#include "SpinSpots.hpp"

/**
 * Inheritance
 * 
 * A class can be defined using another class as a foundation. In object-oriented
 * programming terminology, one class can inherit fi elds and methods from another. 
 * An object that inherits from another is called a subclass, and the object it 
 * inherits from is called a superclass. A subclass extends the superclass.
 */

SpinSpots * spots;
SpinArm * arm;

void setup() {
  size(640, 360);
  arm = new SpinArm(width/2, height/2, 0.01);
  spots = new SpinSpots(width/2, height/2, -0.02, 90.0);
}

void draw() {
  background(204);
  arm->update();
  arm->display();
  spots->update();
  spots->display();
}