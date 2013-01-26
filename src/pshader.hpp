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
        std::string vertSrc;
        std::string fragSrc;

        void release();
        void bindTextures();
        void unbindTextures();
        void setUniform(std::string name, GLfloat value);
        void setUniform(std::string name, GLfloat v0, GLfloat v1);
        void setUniform(std::string name, GLfloat v0, GLfloat v1, GLfloat v2);
        void setUniform(std::string name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
        void setUniform(std::string name, GLint value);
        void setUniform(std::string name, GLint v0, GLint v1);
        void setUniform(std::string name, GLint v0, GLint v1, GLint v2);
        void setUniform(std::string name, GLint v0, GLint v1, GLint v2, GLint v3);
        void setUniformMatrix2(std::string name, const GLfloat * v);
        void setUniformMatrix3(std::string name, const GLfloat * v);
        void setUniformMatrix4(std::string name, const GLfloat * v);
        void setAttribute(std::string name, GLfloat value);
        void setAttribute(std::string name, GLfloat v0, GLfloat v1);
        void setAttribute(std::string name, GLfloat v0, GLfloat v1, GLfloat v2);
        void setAttribute(std::string name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
        void setAttribute(std::string name, GLint value);
        void setAttribute(std::string name, GLint v0, GLint v1);
        void setAttribute(std::string name, GLint v0, GLint v1, GLint v2);
        void setAttribute(std::string name, GLint v0, GLint v1, GLint v2, GLint v3);

        GLuint glProgram;
        GLuint glVertex;
        GLuint glFragment;
        
        PShader();
        PShader(std::string vertSrc, std::string fragSrc);
        ~PShader();

        void setVertexShader(std::string src);
        void setFragmentShader(std::string src);
        void loadVertexShader(std::string src);
        void loadFragmentShader(std::string src);
        bool compileVertexShader();
        bool compileFragmentShader(); 
        void bind();
        void unbind();
        bool bound();
    };
}

#endif
