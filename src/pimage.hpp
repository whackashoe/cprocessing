#include "cprocessing.hpp"


#ifndef CPROCESSING_PIMAGE_
#define CPROCESSING_PIMAGE_


using namespace cprocessing;

namespace cprocessing {     
    enum { ARGB, RGB, HSB, ALPHA };
    
    /// Encapsulates a 2D RGBA image
	class PImage {
	public:
	    GLubyte * texturebuffer; //holds rgba bytes here
        //std::vector<GLubyte> texturebuffer;
	    GLuint textureID; //opengls id for the texture of image

	    PixelColorBuffer pixels;

	    int width;       ///< width of the PImage (size of row)
	    int height;      ///< height of the PImage (number of rows)
        unsigned type;	//TODO ignored 


        PImage();
        PImage(const char * src);
        //inline PImage(String& src) { PImage(src.toCharArray()); }
	    PImage (int w, int h, unsigned type = ARGB);
	    PImage (const char * src, int w, int h, unsigned type = ARGB);
	    //inline PImage(String& src, int w, int h, unsigned type = ARGB) { PImage(src.toCharArray(), w, h, type); }
	    ~PImage ();

	    PImage& operator= (const PImage& p);
	    //bool operator== (const PImage& p);
	    //bool operator!= (const PImage& p);
	    
	    PImage& get();
	    color get(int x, int y);
	    //PImage get (int x, int y, int w, int h); //TODO
        void loadImage(const char * src);
	    //inline void loadImage(String src) { loadImage(src.toCharArray()); }
	    void updatePixels();
        //void mask(const int& maskarray); //TODO
        //void mask(const PImage& img);		//TODO
        void put (int x, int y, int w, int h);
        //void resize(int w, int h);	//TODO
        void save(const char * out);
        //inline void save(String out) { save(out.toCharArray()); }
        void set(int x, int y, const color& c);
	};
}

#endif
