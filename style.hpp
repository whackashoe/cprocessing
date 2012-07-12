/*

#include "cprocessing.hpp"

using namespace cprocessing;

typedef std::vector<double> BlendFactor; ///< Blending factors for a cubic bézier


namespace cprocessing {
<<<<<<< HEAD
    class Style {
    public:
        unsigned rectMode;
        unsigned ellipseMode;
        unsigned imageMode;
        unsigned globColorMode; /// Tells which color space is actually used for color specification

        /// Maximum range values for color components. Specified by the colorMode() function.
        double max1; // First component
        double max2; // Second component
        double max3; // Third component
        double maxA; // Alpha component

        int ellipseDetail;
        int sphereDetail;
        unsigned bezierDetail;

        std::vector<PVector> ellipseVtx;  ///< Vertices of circle centered at the origin and diameter 1
        int ures, vres; ///< number of vertices in the longitude and latitude directions of a sphere
        std::vector<PVector> sphereVtx; ///< Precomputed vertices of a sphere centered at the origin and diameter 1
        std::vector<unsigned> sphereIdx; ///< Indices of sphere vertices traversed by a quadstrip
=======
    struct Style {
        int rectMode;
        int ellipseMode;
        int imageMode;
        int colorMode;

        int ellipseDetail;
        int sphereDetail;
>>>>>>> parent of da2c76e... added Style for push/popstyle

        std::vector<BlendFactor> bezierBlend; ///< bezierDetail samples of Bézier blending functions

        int strokeWeight;

<<<<<<< HEAD
        color * strokeColor;
        color * fillColor;

        float * specular;

        //TODO::
        /*tint(), strokeCap(), strokeJoin(), 
        shapeMode(), textAlign(), textFont(), textMode(), 
        textSize(), textLeading(), emissive(), shininess(), ambient()*/

        Style();
        ~Style();
=======
        color stroke;
        color fill;

        Style ( ) {
            if(styleList.size() > 1) {
                rectMode;
                ellipseMode;
                imageMode;
                colorMode;
                ellipseDetail;
                sphereDetail;
                strokeWeight;
                stroke;
                fill;
            }
        }
>>>>>>> parent of da2c76e... added Style for push/popstyle
    };
}

*/
