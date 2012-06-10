#include <cprocessing/cprocessing.hpp>
using namespace cprocessing;

/**
 * Create Image. 
 * 
 * The createImage() function provides a fresh buffer of pixels to play with.
 * This example creates an image gradient.
 */

void setup() {
  size(640, 360);    
}

void draw() {
  background(0);
    PImage img = createImage(230, 230, ARGB);
      for(int i = 0; i < img.width*img.height; i++) {
        float a = map(i, 0, img.width*img.height, 255, 0);
        img.pixels[i] = color(0, 153, 204, a); 
      }
    println(img.pixels[0].rgba[2]);
   // image(img, 90, 80);
}
