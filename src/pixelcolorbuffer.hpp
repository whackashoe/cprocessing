#include "cprocessing.hpp"
#include "color.hpp"


#ifndef CPROCESSING_PIXELCOLORBUFFER_
#define CPROCESSING_PIXELCOLORBUFFER_

using namespace cprocessing;

namespace cprocessing {
	
	class PixelColorBuffer {	
	public:
		char * b;
		
		PixelColorBuffer(char * b);

		/**Used to pull pixels from the backbuffer
		 * @param x pixel to pull from backbuffer ((y*width)+x)
		 * @returns color at that location
		 */
		color operator[] (int x);
	};

}

#endif