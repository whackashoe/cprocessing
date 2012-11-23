#include <cprocessing/cprocessing.hpp>
#include "eye.hpp"

using namespace cprocessing;


/**
 * Arctangent. 
 * 
 * Move the mouse to change the direction of the eyes. 
 * The atan2() function computes the angle from each eye 
 * to the cursor. 
 */
 
Eye * e1;
Eye * e2;
Eye * e3;

void setup() {
  size(640, 360);
  noStroke();
  e1 = new Eye( 250,  16, 120);
  e2 = new Eye( 164, 185,  80);  
  e3 = new Eye( 420, 230, 220);
}

void draw() {
  background(102);
  
  e1->update(mouseX, mouseY);
  e2->update(mouseX, mouseY);
  e3->update(mouseX, mouseY);

  e1->display();
  e2->display();
  e3->display();
}