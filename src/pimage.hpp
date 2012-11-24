#include <FreeImage.h>
#include "cprocessing.hpp"
#include "color.hpp"
#include "pixelcolorbuffer.hpp"


#ifndef CPROCESSING_PIMAGE_
#define CPROCESSING_PIMAGE_


using namespace cprocessing;

namespace cprocessing {     
    enum { ARGB, RGB, HSB, ALPHA };
    
    /// Encapsulates a 2D RGBA image
	class PImage {
	public:
		int w;	//width of actual image
	    int h; //height of actual image

	    GLubyte * texturebuffer; //holds rgba bytes here
	    GLuint textureID; //opengls id for the texture of image

	    FREE_IMAGE_FORMAT format;
	    FIBITMAP * imagen;
	    FIBITMAP * temp;

	    PixelColorBuffer pixels;

	    int width;       ///< width of the PImage (size of row)
	    int height;      ///< height of the PImage (number of rows)
        unsigned type;


        PImage();
	    /// Constructor
	    /// @arg width horizontal size
	    /// @arg height vertical size
	    /// @arg type ARGB, RGB or ALPHA
	    PImage (int w, int h, unsigned type = ARGB);
	    ~PImage ();
	    
	    PImage& get();
	    color get(int x, int y);
	    //PImage get (int x, int y, int w, int h);
        void loadImage(const char * src);
        void loadPixels();
        void mask(const int& maskarray);
        void mask(const PImage& img);
        void put (int x, int y, int w, int h);
        void resize(int w, int h);
        //void save(String s);
        void set(int x, int y, const color& c);
        void updatePixels();
        void updatePixels(int x, int y, int w, int h);
	};
}

#endif