#include "cprocessing.hpp"

#ifndef CPROCESSING_COLOR_
#define CPROCESSING_COLOR_
#define MAXCOLOR 1e10
namespace cprocessing {  
    //blend types
    typedef enum {
        REPLACE, BLEND, ADD, SUBTRACT, DARKEST, LIGHTEST, DIFFERENCE, EXCLUSION, MULTIPLY, SCREEN, OVERLAY, HARD_LIGHT, SOFT_LIGHT, DODGE, BURN
    } BlendMode;
    
	/// Color class
	struct color {
		unsigned char rgba[4];
		/// Empty constructor
		color () {}
		/// Constructor
		color (double r, double g, double b, double a = MAXCOLOR);
		/// Constructor for gray values
		color (double gray, double alpha = MAXCOLOR);
		//constructor for hex values
		color (std::string);
		
		/// Fills a float array with color values scaled for the interval 0..1
		void toFloat(float a[]);
		/// Fills a double array with color values scaled for the interval 0..1
		void toDouble(double a[]);
	};

    	/// Changes the way Processing interprets color data.
	/// The colorMode() function is used to change the numerical range used for specifying colors and to switch color systems.
	void colorMode(unsigned mode, double range1, double range2, double range3, double range4);

	void colorMode(unsigned mode);

	inline void colorMode(unsigned mode, double range){
		colorMode(mode, range, range, range, range);
	}

	inline void colorMode(unsigned mode, double range1, double range2, double range3){
		colorMode(mode, range1, range2, range3, MAXCOLOR);
	}

	/// Extracts the alpha value from a color, scaled to match current colorMode()
	double alpha(const color & color);
	
	/// Extracts the red value from a color, scaled to match current colorMode()
	double red(const color & color);
	
	/// Extracts the green value from a color, scaled to match current colorMode()
	double green(const color & color);
	
	/// Extracts the blue value from a color, scaled to match current colorMode()
	double blue(const color & color);
	
	/// Extracts the hue value from a color, scaled to match current colorMode()
	double hue(const color & color);
	
	/// Extracts the saturation value from a color, scaled to match current colorMode()
	double saturation(const color & color);
	
	/// Extracts the brightness value from a color, scaled to match current colorMode()
	double brightness(const color & color);
	
    //Blends two colors together
    color blendColor(const color, const color, unsigned mode = BLEND);
}
#endif