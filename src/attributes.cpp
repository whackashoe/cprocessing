#include "cprocessing.hpp"

using namespace cprocessing;
namespace cprocessing {

    /// Sets line color
    /// @param c New line color
    void stroke (const color& c) {
        styles[styles.size()-1].strokeColor = color(c);
    }

    /// Sets area color
    /// @param c New area color
    void fill (const color& c) {
      styles[styles.size()-1].fillColor = color(c);
    }

    /// Sets line / point width
    /// @param weight: New breadth of line in pixels
    void strokeWeight (int weight) {
        //TODO:: styles[styles.size()-1].strokeWeight = weight;
        glLineWidth (weight);
        glPointSize (weight);
    }


    /// Clear the window with a background color
    /// @param c: background color
    void background (const color& c) {
        glClearColor (c.rgba[0] * (1.0/255),
                      c.rgba[1] * (1.0/255),
                      c.rgba[2] * (1.0/255),
                      c.rgba[3] * (1.0/255));
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    /// Clear the window with a background image
    /// @param img: background image
    void background (PImage& img) {
        background(color(0));
        image(img, 0, 0, width, height);
    }

    void background (PImage * img) {
        background(color(0));
        image(img, 0, 0, width, height);
    }

    /// Sets state so that lines are rendered antialiased.
    void smooth() {
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    }

    /// Sets state so that lines are rendered quickly.
    void noSmooth() {
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
    }

}