#include <cprocessing.hpp>
using namespace cprocessing;

/**
 * Conditionals 2. 
 * 
 * We extend the language of conditionals from the previous
 * example by adding the keyword "else". This allows conditionals 
 * to ask two or more sequential questions, each with a different
 * action. 
 */

void setup() {
    size(640, 360);
    background(0);
}

void draw() {
    for(int i = 2; i < width-2; i += 2) {
      // If 'i' divides by 20 with no remainder
      if((i % 20) == 0) {
        stroke(255);
        line(i, 80, i, height/2);
      // If 'i' divides by 10 with no remainder
      } else if ((i % 10) == 0) {
        stroke(153);
        line(i, 20, i, 180); 
      // If neither of the above two conditions are met
      // then draw this line
      } else {  
        stroke(102);
        line(i, height/2, i, height-20);
      }
    }
}