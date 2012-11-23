#include <cprocessing/cprocessing.hpp>
#include "Spot.hpp"

/**
 * Multiple constructors
 * 
 * A class can have multiple constructors that assign the fields in different ways. 
 * Sometimes it's beneficial to specify every aspect of an object's data by assigning 
 * parameters to the fields, but other times it might be appropriate to define only 
 * one or a few.
 */

Spot * sp1;
Spot * sp2;

void setup() {
  size(640, 360);
  background(204);
  noLoop();
  // Run the constructor without parameters
  sp1 = new Spot();
  // Run the constructor with three parameters
  sp2 = new Spot(width*0.5, height*0.5, 120);
}

void draw() {
  sp1->display();
  sp2->display();
}