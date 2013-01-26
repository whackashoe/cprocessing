#include "cprocessing.hpp"

#ifndef CPROCESSING_PLIGHTS_
#define CPROCESSING_PLIGHTS_

using namespace cprocessing;
namespace cprocessing {
    /// Defines a new directional light.
    /// @arg v1, v2, v3: color components.
    /// @arg nx, ny, nz: direction vector.
    void directionalLight(float v1, float v2, float v3,
                          float nx, float ny, float nz);

    /// Defines a new directional light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void pointLight(float  v1,float  v2,float  v3,float  x,float  y,float  z);

    /// Defines a new ambient light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void ambientLight(float  v1,float  v2,float  v3, float  x=0, float  y=0, float  z=0);

    /// Defines a new spot light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    /// @arg nx, ny, nz: direction vector.
    /// @arg angle: angle in radians of spot aperture.
    /// @arg concentration: exponent which determines preference for spot axis.
    void spotLight(float v1, float  v2, float  v3,
                   float  x, float  y, float  z,
                   float  nx, float ny,float  nz,
                   float  angle, float  concentration);

    /// Defines a specular coefficients of new light sources.
    /// @arg v1, v2, v3: color components.
    void lightSpecular (float v1,float  v2,float  v3);

    /// Defines light attenuation factors
    /// @arg constant, linear, quadratic: coefficients of quadratic polynomial.
    void lightFalloff(float  constant,float  linear,float  quadratic);

    /// Turns on the default lighting
    void lights();

    // Turns off the lights
    void noLights();

}

#endif