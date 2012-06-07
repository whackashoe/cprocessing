#include <cprocessing.hpp>
using namespace cprocessing;

/**
 * Variables. 
 * 
 * Variables are used for storing values. In this example, change 
 * the values of variables to affect the composition. 
 */

void setup() {
    size(640, 360);
    stroke(153);
    strokeWeight(4);
}

void draw() {
    background(0);

    int a = 50;
    int b = 120;
    int c = 180;

    line(a, b, a+c, b);
    line(a, b+10, a+c, b+10);
    line(a, b+20, a+c, b+20);
    line(a, b+30, a+c, b+30);

    a = a + c;
    b = height-b;

    line(a, b, a+c, b);
    line(a, b+10, a+c, b+10);
    line(a, b+20, a+c, b+20);
    line(a, b+30, a+c, b+30);

    a = a + c;
    b = height-b;

    line(a, b, a+c, b);
    line(a, b+10, a+c, b+10);
    line(a, b+20, a+c, b+20);
    line(a, b+30, a+c, b+30);
}
