/*
 * attributes.cpp
 *
 *  Created on: Jul 20, 2011
 *      Author: claudio
 */

#include <GL/glut.h>
#include <iostream>
#include "cprocessing.hpp"

using namespace cprocessing;


namespace cprocessing {
    /// Sets line color
    /// @param color: New line color
    void stroke (const color& c) {
        strokeColor = c;
    }

    /// Sets area color
    /// @param color: New area color
    void fill (const color& c) {
        fillColor = c;
    }

    /// Sets line / point width
    /// @param weight: New breadth of line in pixels
    void strokeWeight (int weight) {
        glLineWidth (weight);
        glPointSize (weight);
    }


    /// Clear the window with a background color
    /// @param color: background color
    void background (const color& c) {
        glClearColor (c.rgba[0] * (1.0/255),
                      c.rgba[1] * (1.0/255),
                      c.rgba[2] * (1.0/255),
                      c.rgba[3] * (1.0/255));
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    /// Sets state so that lines are rendered antialiased.
    void smooth() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    }

    /// Sets state so that lines are rendered quickly.
    void noSmooth() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
    }

}
