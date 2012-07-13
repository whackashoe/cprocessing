#ifndef CPROCESSING_STYLE
#define CPROCESSING_STYLE

#include "cprocessing.hpp"
#include "color.hpp"

using namespace cprocessing;

typedef std::vector<double> BlendFactor; ///< Blending factors for a cubic bézier


namespace cprocessing {
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

        std::vector<BlendFactor> bezierBlend; ///< bezierDetail samples of Bézier blending functions

        int strokeWeight;   //TODO:: have this actually affect past generations when popstyle is called (along with other things such as details)

        color strokeColor;
        color fillColor;

        float * specular;

        //TODO::
        /*tint(), strokeCap(), strokeJoin(), 
        shapeMode(), textAlign(), textFont(), textMode(), 
        textSize(), textLeading(), emissive(), shininess(), ambient()*/

        Style();
        ~Style();
    };
}

#endif