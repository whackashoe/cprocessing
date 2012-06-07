#include "cprocessing.hpp"

#ifndef CPROCESSING_PIMAGE_
#define CPROCESSING_PIMAGE_


using namespace cprocessing;

namespace cprocessing {     
    enum { ARGB };
    
    /// Encapsulates a 2D RGBA image
	class PImage {
	public:
	    color * pixels;  ///< Where the pixels are actually stored. Stored row by row
	                     /// from top (row 0) to bottom
	    int width;       ///< width of the image (size of row)
	    int height;      ///< height of the image (number of rows)
	    
	    /// Constructor
	    /// @arg width horizontal size
	    /// @arg height vertical size
	    /// @arg type ARGB, RGB or ALPHA
	    PImage (int width, int height, int type = ARGB);
	    
	    /// Destructor
	    ~PImage ();
	    
	    /// Returns a copy of this image
	    PImage get(); 
	    
	    /// Returns a copy of a subrectangle of this image
	    PImage get (int x, int y, int w, int h);
    
	    /// Returns the pixel at coordinate (x,y) 
	    inline color get(int x, int y) {
	        assert(x >=0 && x < width && y >= 0 && y < height && pixels!=0);
	        return pixels[y*width+x];
	    }	    
	    
	    /// Draws the image at position (x, y) of the screen
	    void put (int x, int y);
	    
	    /// Draws the image at position (x, y) of the screen with the given width and height
	    void put (int x, int y, int w, int h);	    
	};
}

#endif