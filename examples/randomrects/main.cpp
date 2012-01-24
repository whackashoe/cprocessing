#include <cprocessing.hpp>
#include <cstdlib> 
#include <vector>

using namespace std;
using namespace cprocessing;

// A random moving rectangle
class RandomRect {
public:
    color c; // Color
    float x,y,w,h; // Position and size
    float vx,vy; // Speed
    
    // Constructor
    RandomRect () {
        c = color (random()%255,random()%255,random()%255);
        if (rand () % 2 == 0) {
            // Horizontally moving rectangle
            vx = random () % 100 / 100.0;
            vy = 0;
            x = -random () % width;
            y = random () % (3*height) - height;
            w = random () % 10 + width / 50.0;
            h = random () % 10 + height / 50.0;
        }
        else {
            // Vertically moving rectangle
            vy = random () % 100 / 100.0;
            vx = 0;
            y = -random () % height;
            x = random () % (3*width) - width;
            w = random () % 10 + width / 50.0;
            h = random () % 10 + height / 50.0;
        }

    }
    
    // Draw the rectangle
    void draw () {
        fill (c);
        rect (x, y, w, h);
    }
    
    // Move the rectangle
    void move () {
        x += vx;
        y += vy;
    }
    
    bool outside () {
        if (vy == 0) { 
            return x > width;
        }
        else {
            return y > height;
        }
    }
};


vector<RandomRect> rects;
int n = 10000;

void draw () {
	background(200);
	for (int i = 0;  i < rects.size(); i++) {
	    rects [i].move();
	    rects [i].draw();
	    if (rects[i].outside()) {
	        rects[i] = RandomRect();
	    }
	}
	//redraw();	//currently does not work
}

void setup() {
	size (500,500);
	for (int i = 0;  i < n; i++) {
	    rects.push_back(RandomRect());
	}
	noStroke();
}

