#include "cprocessing.hpp"


#ifndef CPROCESSING_PIXELCOLORBUFFER_
#define CPROCESSING_PIXELCOLORBUFFER_


using namespace cprocessing;

namespace cprocessing {
	
	class PixelColorBuffer {	
	public:
        unsigned char ** b;
		
		PixelColorBuffer();
		void setBuffer(unsigned char *& b);

		/**Used to pull pixels from the buffer
		 * @param x pixel to pull from buffer ((y*width)+x)
		 * @returns color at that location*/
		color operator[] (int x);

		/**Converts a pixel from the buffer into the color
		* @param n pixel ((y*width)+x)
		* @return color*/
		color buffertocolor(int n);

		/**Converts a pixel from the buffer into the color
		* @param n pixel ((y*width)+x)
		* @param c color to put into buffer*/
	    void colortobuffer(int n, const color& c);
	};
}

#endif
