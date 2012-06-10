#include "cprocessing.hpp"
#include <Magick++.h>

#ifndef CPROCESSING_PIMAGE_
#define CPROCESSING_PIMAGE_


using namespace cprocessing;
using namespace Magick;

namespace cprocessing {     
    enum { ARGB, RGB, HSB, ALPHA };
    
    /// Encapsulates a 2D RGBA image
	class PImage {
	public:
	    color * pixels;  ///< Where the pixels are actually stored. Stored row by row
	                     /// from top (row 0) to bottom
        Image * img;
	    int width;       ///< width of the image (size of row)
	    int height;      ///< height of the image (number of rows)
        unsigned type;


        PImage();
	    /// Constructor
	    /// @arg width horizontal size
	    /// @arg height vertical size
	    /// @arg type ARGB, RGB or ALPHA
	    PImage (int w, int h, unsigned type = ARGB);
	    
	    /// Destructor
	    ~PImage ();
	    
	    /// Returns a copy of this image
	    PImage get(); 
	    
	    /// Returns a copy of a subrectangle of this image
	    PImage get (int x, int y, int w, int h);

        void loadImage(std::string src);
            
	    /// Returns the pixel at coordinate (x,y) 
	    inline color get(int x, int y) {
	        assert(x >=0 && x < width && y >= 0 && y < height && pixels!=0);
	        return pixels[y*width+x];
	    }	    

        //sets a pixel to a color
        void set(int x, int y, const color& c);
	    
	    /// Draws the image at position (x, y) of the screen
	    void put (int x, int y);
	    
	    /// Draws the image at position (x, y) of the screen with the given width and height
	    void put (int x, int y, int w, int h);	    
	};
}

#endif