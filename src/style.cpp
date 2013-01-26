#include "cprocessing.hpp"

using namespace cprocessing;
namespace cprocessing {
	Style::Style() {
		if(styles.size() > 0) {
			/*strokeColor.rgba[0] = styles[styles.size()-1].strokeColor.rgba[0];     ///< Line drawing color
			strokeColor.rgba[1] = styles[styles.size()-1].strokeColor.rgba[1];
			strokeColor.rgba[2] = styles[styles.size()-1].strokeColor.rgba[2];
			strokeColor.rgba[3] = styles[styles.size()-1].strokeColor.rgba[3];
			fillColor.rgba[0]   = styles[styles.size()-1].fillColor.rgba[0];   ///< Area drawing color
			fillColor.rgba[1]   = styles[styles.size()-1].fillColor.rgba[1];
			fillColor.rgba[2]   = styles[styles.size()-1].fillColor.rgba[2];
			fillColor.rgba[3]   = styles[styles.size()-1].fillColor.rgba[3];*/
			strokeColor = styles[styles.size()-1].strokeColor;
			fillColor = styles[styles.size()-1].fillColor;



			rectMode 		= styles[styles.size()-1].rectMode;  ///< Rectangle drawing mode
			ellipseMode		= styles[styles.size()-1].ellipseMode; ///< Ellipse drawing mode
			globColorMode 	= styles[styles.size()-1].globColorMode;
			imageMode 		= styles[styles.size()-1].imageMode;
			strokeWeight	= styles[styles.size()-1].strokeWeight;
			sphereDetail	= styles[styles.size()-1].sphereDetail;
			ellipseDetail	= styles[styles.size()-1].ellipseDetail;
			bezierDetail	= styles[styles.size()-1].bezierDetail;
			
			specular 		= new float[4];
			specular[0]		= styles[styles.size()-1].specular[0];
			specular[1]		= styles[styles.size()-1].specular[1];
			specular[2]		= styles[styles.size()-1].specular[2];
			specular[3]		= styles[styles.size()-1].specular[3];
			
			ellipseVtx	 	= styles[styles.size()-1].ellipseVtx; 
	        ures 			= styles[styles.size()-1].ures;
	        vres 			= styles[styles.size()-1].vres;
	        sphereVtx 		= styles[styles.size()-1].sphereVtx;
	        sphereIdx 		= styles[styles.size()-1].sphereIdx;
			bezierBlend		= styles[styles.size()-1].bezierBlend; ///< bezierDetail samples of Bézier blending functions
		} else {
			rectMode 		= CORNER;  ///< Rectangle drawing mode
			ellipseMode		= CENTER; ///< Ellipse drawing mode
			globColorMode 	= RGB;
			max1 			= 255;  // First component
	        max2 			= 255;  // Second component
	        max3 			= 255;  // Third component
	        maxA 			= 255;  // Alpha component
			imageMode 		= CORNER;
			strokeWeight	= 1;
			sphereDetail	= 10;
			ellipseDetail	= 30;
			bezierDetail	= 50;

			specular 		= new float[4];
			specular[0]		= 0;
			specular[1]		= 0;
			specular[2]		= 0;
			specular[3]		= 1;
		}
	}

	void pushStyle() {
		Style * newStyle = new Style;
		styles.push_back(*newStyle);
	}

	void popStyle() {
		if(styles.size() > 1) styles.pop_back();
		else                  printerr("cannot have more popStyles() than pushStyles()");
	}

	/*
	//TODO
	Style::~Style() {} & copy etc
	*/

}