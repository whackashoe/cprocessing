#include "cprocessing.hpp"

using namespace cprocessing;

Style::Style() {
	if(styles.size() > 0) {
		delete strokeColor;
		delete fillColor;
		strokeColor 	= styles[styles.size()-1].strokeColor;     ///< Line drawing color
		fillColor   	= styles[styles.size()-1].fillColor;   ///< Area drawing color
		rectMode 		= styles[styles.size()-1].rectMode;  ///< Rectangle drawing mode
		ellipseMode		= styles[styles.size()-1].ellipseMode; ///< Ellipse drawing mode
		globColorMode 	= styles[styles.size()-1].globColorMode;
		imageMode 		= styles[styles.size()-1].imageMode;
		strokeWeight	= styles[styles.size()-1].strokeWeight;
		sphereDetail	= styles[styles.size()-1].sphereDetail;
		ellipseDetail	= styles[styles.size()-1].ellipseDetail;

		specular[0]		= styles[styles.size()-1].specular[0];
		specular[1] 	= styles[styles.size()-1].specular[1];
		specular[2] 	= styles[styles.size()-1].specular[2];
		specular[3] 	= styles[styles.size()-1].specular[3];

		ellipseVtx	 	= styles[styles.size()-1].ellipseVtx; 
        ures 			= styles[styles.size()-1].ures;
        vres 			= styles[styles.size()-1].vres;
        sphereVtx 		= styles[styles.size()-1].sphereVtx;
        sphereIdx 		= styles[styles.size()-1].sphereIdx;
	}/* else {
		strokeColor 	= new color(0);
		fillColor 		= new color(255);
		rectMode 		= CORNER;  ///< Rectangle drawing mode
		ellipseMode		= CENTER; ///< Ellipse drawing mode
		globColorMode 	= RGB;
		imageMode 		= CORNER;
		strokeWeight	= 1;
		sphereDetail	= 10;
		ellipseDetail	= 30;

		specular[0]		= 0; 
		specular[1] 	= 0; 
		specular[2] 	= 0; 
		specular[3] 	= 1;
	}*/
}

Style::~Style() {
	delete strokeColor;
	delete fillColor;
}