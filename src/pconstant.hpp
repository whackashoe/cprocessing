#ifndef CPROCESSING_PCONSTANT_
#define CPROCESSING_PCONSTANT_

using namespace cprocessing;


namespace cprocessing {

	const double PI 			= 3.14159265358979323846264338327950288;	/**< PI   */
	const double TWO_PI 		= 2*PI;						/**< PI*2 */
	const double HALF_PI 		= PI/2;						/**< PI/2 */
	const double QUARTER_PI 	= PI/4;						/**< PI/4 */
	const double EIGHTH_PI 		= PI/4;						/**< PI/8 */
	const double GOLDEN_RATIO 	= 1.61803398874989484820458683436563811;
	const double EULERS_NUMBER 	= 2.71828182845904523536028747135266249;
	const double PYTHAGORAS 	= 1.41421356237309504880168872420969807; //SQRT(2)

	/// Used to test keys
	enum { CODED = 255, RETURN = '\r', ENTER = '\n',
		   ESC = 27, TAB = '\t', DELETE = 127
	};

	/// Other constants
	enum { F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		   UP, DOWN, LEFT, RIGHT, CENTER, PAGEUP, PAGEDOWN, HOME, END, INSERT,
		   RADIUS, CORNER, CORNERS
	};

	/// Configuration flags
	enum {
		HALF_PIXEL_SHIFT = 0,    // Whether to shift vertex coordinates by half a pixel (false by default, true makes images slide).
		Y_DOWN           = 1<<1, // Whether to flip the y axis so it points down, rather than up (true by default).
		BACK_BUFFER		 = 1<<2  // Whether to use a backup buffer which is copied every frame in order to effect a stable drawing
		                         // canvas which is maintained between frames (true by default, but should be disabled for speed).
	};

	/// Shape constants
	typedef enum {
		POINTS, LINES, LINE_LOOP, LINE_STRIP, TRIANGLES, TRIANGLE_STRIP, TRIANGLE_FAN, QUADS, QUAD_STRIP, POLYGON
	} ShapeMode;


	/// Parameter for the endShape function
	typedef enum {
		OPEN = 0, CLOSE = 1
	} ShapeClose;

	//blend types
    typedef enum {
        REPLACE, BLEND, ADD, SUBTRACT, DARKEST, LIGHTEST, DIFFERENCE, EXCLUSION, MULTIPLY, SCREEN, OVERLAY, HARD_LIGHT, SOFT_LIGHT, DODGE, BURN
    } BlendMode;

    //color image types
    enum { ARGB, RGB, HSB, ALPHA };
}
	
#endif