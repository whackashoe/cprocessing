#include <GL/glut.h>
#include <string>
#include "cprocessing.hpp"


#ifndef PSHADER_H_
#define PSHADER_H_

namespace cprocessing {

    class PShader {
    private:
        int maxLength;
        GLint IsCompiled_FS;
        GLint IsCompiled_VS;

        void init();
        char * filetobuf(char * src);
    public:
        char * vertSrc;
        char * fragSrc;
        bool isbound;

        void release();
        void bindTextures();
        void unbindTextures();

        GLuint glProgram;
        GLuint glVertex;
        GLuint glFragment;
        
        PShader();
        PShader(char * vertSrc, char * fragSrc);

        void setVertexShader(char * src);
        void setFragmentShader(char * src);
        bool compileVertexShader();
        bool compileFragmentShader(); 
        void bind();
        void unbind();
        bool bound();
    };
}

#endif
