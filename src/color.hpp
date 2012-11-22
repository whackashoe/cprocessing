#include "cprocessing.hpp"

#ifndef CPROCESSING_COLOR_
#define CPROCESSING_COLOR_
#define MAXCOLOR 1e10

#ifdef DIFFERENCE
#undef DIFFERENCE
#endif

namespace cprocessing {  
    //blend types
    typedef enum {
        REPLACE, BLEND, ADD, SUBTRACT, DARKEST, LIGHTEST, DIFFERENCE, EXCLUSION, MULTIPLY, SCREEN, OVERLAY, HARD_LIGHT, SOFT_LIGHT, DODGE, BURN
    } BlendMode;
    
	/// Color class
	class color {
	private:
		/**Converts hexadecimal digit to int
		 * @param c character
		 * @returns number between 0-16*/
		int htoi(const char& c);
	public:
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


	/*! \relates color
	* Changes the way Processing interprets color data. The colorMode() function is used to change the numerical range used for specifying colors and to switch color systems.
	* @param mode Either RGB or HSB, corresponding to Red/Green/Blue and Hue/Saturation/Brightness*/
	void colorMode(unsigned mode);

    /*! \relates color
    * Changes the way Processing interprets color data. The colorMode() function is used to change the numerical range used for specifying colors and to switch color systems.    
    * @param mode Either RGB or HSB, corresponding to Red/Green/Blue and Hue/Saturation/Brightness
    * @param range1 range for the red or hue depending on the current color mode
    * @param range2 range for the green or saturation depending on the current color mode
    * @param range3 range for the blue or brightness depending on the current color mode
    * @param range4 range for the alpha*/
    void colorMode(unsigned mode, double range1, double range2, double range3, double range4);

	/*! \relates color
	* Changes the way Processing interprets color data. The colorMode() function is used to change the numerical range used for specifying colors and to switch color systems.
	* @param mode Either RGB or HSB, corresponding to Red/Green/Blue and Hue/Saturation/Brightness
	* @param range range for all colors*/
	inline void colorMode(unsigned mode, double range){
		colorMode(mode, range, range, range, range);
	}

	/*! \relates color
	* Changes the way Processing interprets color data. The colorMode() function is used to change the numerical range used for specifying colors and to switch color systems.
	* @param mode Either RGB or HSB, corresponding to Red/Green/Blue and Hue/Saturation/Brightness
	* @param range1 range for the red or hue depending on the current color mode
	* @param range2 range for the green or saturation depending on the current color mode
	* @param range3 range for the blue or brightness depending on the current color mode*/
	inline void colorMode(unsigned mode, double range1, double range2, double range3){
		colorMode(mode, range1, range2, range3, MAXCOLOR);
	}
	
	/*! \relates color
	* Extracts the alpha value from a color, scaled to match current colorMode()
	* @param color any color
    * @return value between 0 and range of colorMode() (default 255.0)*/
	double alpha(const color & color);
	
	/*! \relates color
	* Extracts the red value from a color, scaled to match current colorMode()
	* @param color any color
    * @return value between 0 and range of colorMode() (default 255.0)*/
	double red(const color & color);
	
	/*! \relates color
	* Extracts the green value from a color, scaled to match current colorMode()
	* @param color any color
    * @return value between 0 and range of colorMode() (default 255.0)*/
	double green(const color & color);
	
	/*! \relates color
	* Extracts the blue value from a color, scaled to match current colorMode()
	* @param color any color
    * @return value between 0 and range of colorMode() (default 255.0)*/
	double blue(const color & color);
	
	/*! \relates color
	* Extracts the hue value from a color, scaled to match current colorMode()
	* @param color any color
    * @return value between 0 and range of colorMode() (default 255.0)*/
	double hue(const color & color);
	
	/*! \relates color
	* Extracts the saturation value from a color, scaled to match current colorMode()
	* @param color any color
    * @return value between 0 and range of colorMode() (default 255.0)*/
	double saturation(const color & color);
	
	/*! \relates color
	* Extracts the brightness value from a color, scaled to match current colorMode()
    * @param color any color
    * @return value between 0 and range of colorMode() (default 255.0)*/
	double brightness(const color & color);

		
    /* ! \relates color
    * Blends two colors together using one of the possible blending modes (REPLACE, BLEND, ADD, SUBTRACT, DARKEST, LIGHTEST, DIFFERENCE, EXCLUSION, MULTIPLY, SCREEN, OVERLAY, HARD_LIGHT, SOFT_LIGHT, DODGE, BURN)
	* @param a any color
	* @param b any color
	* @param mode blending mode
    * @return new color*/
    color blendColor(const color& a, const color& b, unsigned mode = BLEND);
    /*! \relates color
    * Calculates a color or colors between two color at a specific increment. The amt parameter is the amount to interpolate between the two values where 0.0 equal to the first point, 0.1 is very near the first point, 0.5 is halfway in between, etc. 
	* @param a any color
	* @param b any color
	* @param amt amount to interpolate between 0.0 and 1.0
    * @return new color*/
    color lerpColor(const color& a, const color& b, double amt);
}
#endif
