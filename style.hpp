#ifndef CPROCESSING_STYLE
#define CPROCESSING_STYLE

#include "cprocessing.hpp"
#include "color.hpp"

using namespace cprocessing;

namespace cprocessing {
    class Style {
    public:
        unsigned rectMode;
        unsigned ellipseMode;
        unsigned imageMode;
        unsigned globColorMode;

        int ellipseDetail;
        int sphereDetail;
        
        std::vector<PVector> ellipseVtx;  ///< Vertices of circle centered at the origin and diameter 1
        int ures, vres; ///< number of vertices in the longitude and latitude directions of a sphere
        std::vector<PVector> sphereVtx; ///< Precomputed vertices of a sphere centered at the origin and diameter 1
        std::vector<unsigned> sphereIdx; ///< Indices of sphere vertices traversed by a quadstrip

        int strokeWeight;

        color * strokeColor;
        color * fillColor;

        float specular[4];

        //TODO::
        /*tint(), strokeCap(), strokeJoin(), 
        shapeMode(), textAlign(), textFont(), textMode(), 
        textSize(), textLeading(), emissive(), shininess(), ambient()*/

        Style();
        ~Style();
    };
}

#endif