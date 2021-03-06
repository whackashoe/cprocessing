#include <cprocessing/cprocessing.hpp>
using namespace cprocessing;

/**
 * Pie Chart  
 * By Ira Greenberg 
 * 
 * Uses the arc() function to generate a pie chart from the data
 * stored in an array. 
 */


float diameter;
int angles[8] = { 30, 10, 45, 35, 60, 38, 75, 67 };
float lastAngle = 0;

void setup() {
  size(640, 360);
  background(100);
  noStroke();
  diameter = min(width, height) * 0.75;
}


void draw() {
  for (int i = 0; i < 8; i++) {
    fill(angles[i] * 3.0);
    arc(width/2, height/2, diameter, diameter, lastAngle, lastAngle+radians(angles[i]));
    lastAngle += radians(angles[i]);
  }
  noLoop();  // Run once and stop
}

