#include "cprocessing.hpp"


#ifndef PSHADER_H_
#define PSHADER_H_

namespace cprocessing {

    class PShader {
    private:
        bool isbound;
        int maxLength;
        GLint IsCompiled_FS;
        GLint IsCompiled_VS;
        
        void init();
    public:
        const char * vertSrc;
        const char * fragSrc;

        void release();
        void bindTextures();
        void unbindTextures();
        void setUniform(const char * name, float value);

        GLuint glProgram;
        GLuint glVertex;
        GLuint glFragment;
        
        PShader();
        PShader(const char * vertSrc, const char * fragSrc);
        ~PShader();

        void setVertexShader(const char * src);
        void setFragmentShader(const char * src);
        bool compileVertexShader();
        bool compileFragmentShader(); 
        void bind();
        void unbind();
        bool bound();
    };
}

#endif
