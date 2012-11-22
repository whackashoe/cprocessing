#include <cprocessing/cprocessing.hpp>
#include "Spot.hpp"

  
// First version of the Spot constructor;
// the fields are assigned default values
Spot::Spot() {
  radius = 40;
  x = width*0.25;
  y = height*0.5;
}

// Second version of the Spot constructor;
// the fields are assigned with parameters
Spot::Spot(float xpos, float ypos, float r) {
  x = xpos;
  y = ypos;
  radius = r;
}

void Spot::display() {
  ellipse(x, y, radius*2, radius*2);
}