#include "cprocessing.hpp"

#ifndef CPROCESSING_SCREENPIXELS_
#define CPROCESSING_SCREENPIXELS_

using namespace cprocessing;
namespace cprocessing {

	/**Updates pixels you have saved into buffer */
	void updatePixels();

	/**Loads all the pixels on the screen into buffer*/
	void loadPixels();

	/**Loads a group of colors from the screen from specific coordinate and width/height into buffer
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param w amount of pixels to grab to the right of x
     * @param h amount of pixels to grab to the right of y*/
	void loadPixels(int x, int y, int w, int h);

	/**Grabs a color from the screen at a specific coordinate, must call loadPixels() first
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @return color at that place*/
	color get(int x, int y);

	/**Grabs a group of colors from the screen from specific coordinate and width/height, must call loadPixels() first
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param w amount of pixels to grab to the right of x
     * @param h amount of pixels to grab to the right of y
     * @return vector of colors grabbed*/
	ArrayList<color> get(int x, int y, int w, int h);
	
	/**Sets a pixel at coordinates to specific color
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param c color to set*/
	void set(int x, int y, const color& c);

	/**Sets a group of pixels at coordinates to specific color
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param w amount of pixels to set to the right of x
     * @param h amount of pixels to set to the right of y
     * @param c color to set*/
	void set(int x, int y, int w, int h, const color& c);

}

#endif