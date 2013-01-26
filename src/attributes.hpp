#include "cprocessing.hpp"

#ifndef CPROCESSING_ATTRIBUTES_
#define CPROCESSING_ATTRIBUTES_

using namespace cprocessing;
namespace cprocessing {	
	/// Sets line color
	void stroke (const color& c);

	inline void stroke (double r, double g, double b, double a = MAXCOLOR) {
		stroke (color (r,g,b,a));
	}

	inline void stroke (double gray, double a = MAXCOLOR) {
		stroke (color (gray,a));
	}

	inline void noStroke() {
		stroke (color(0,0,0,0));
	}

	/// Sets fill color
	void fill (const color & color);

	inline void fill (double r, double g, double b, double a = MAXCOLOR) {
		fill (color (r,g,b,a));
	}

	inline void fill (double gray, double a = MAXCOLOR) {
		fill (color (gray,a));
	}

    inline void fill (const color c, double a) {
        fill (color (c.rgba[0], c.rgba[1], c.rgba[2], a));
    }

	inline void noFill() {
		fill (color(0,0,0,0));
	}

	/// Sets line / point width
	void strokeWeight (int weight);

	/// Draws background with given color
	void background (const color& c);

	void background(PImage * img);
	void background(PImage& img);

	inline void background (double r, double g, double b, double a = MAXCOLOR) {
		background (color (r,g,b,a));
	}

	inline void background (double gray, double a) {
		background (color (gray,a));
	}

	inline void background(int gray) {
		background(color(gray, MAXCOLOR));
	}

	// Line smoothing
	void smooth(); ///< Turns on smoothing

	void noSmooth(); ///< Turns off smoothing
}

#endif