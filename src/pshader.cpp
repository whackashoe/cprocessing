#include "cprocessing.hpp"

PShader::PShader() {
    assert(initialized);
    init();
}

PShader::PShader(const char * vertSrc, const char * fragSrc) {
    assert(initialized);
    init();
    this->setVertexShader(vertSrc);
    this->setFragmentShader(fragSrc);
}

PShader::~PShader() {
    glDeleteProgram(glProgram);
    if(IsCompiled_VS) glDeleteShader(glVertex);
    if(IsCompiled_VS) glDeleteShader(glFragment);
}

void PShader::init() {
    maxLength = 4096;
    IsCompiled_FS = 0;
    IsCompiled_VS = 0;
    glProgram = glCreateProgram();
}

void PShader::setVertexShader(const char * src) {
    this->vertSrc = loadBytes(src);
    compileVertexShader();
    glAttachShader(glProgram, glFragment);
    glLinkProgram(glProgram);
}

void PShader::setFragmentShader(const char * src) {
    this->fragSrc = loadBytes(src);
    compileFragmentShader();
    glAttachShader(glProgram, glVertex);
    glLinkProgram(glProgram);
}

void PShader::bind() {
    glUseProgram(glProgram);
    isbound = true;
}

void PShader::unbind() {
    glUseProgram(0);
    isbound = false;
}

void PShader::setUniform(const char * name, float value) {
    glUniform1f(glGetUniformLocation(glProgram, name), value);
}

bool PShader::bound() {
    return isbound;
}

void PShader::release() {

}

void PShader::bindTextures() {

}

void PShader::unbindTextures() {

}

bool PShader::compileFragmentShader() {
    glFragment = glCreateShader(GL_FRAGMENT_SHADER);
   
    glShaderSource(glFragment, 1, (const GLchar**)&fragSrc, 0);
    glCompileShader(this->glFragment);
    glGetShaderiv(this->glFragment, GL_COMPILE_STATUS, &IsCompiled_FS);

    if(this->IsCompiled_FS == false) {
        glGetShaderiv(this->glFragment, GL_INFO_LOG_LENGTH, &this->maxLength);
        char * fragmentInfoLog = (char *)malloc(maxLength);
        glGetShaderInfoLog(glFragment, maxLength, &maxLength, fragmentInfoLog);
        println(fragmentInfoLog);
        free(fragmentInfoLog);
        return false;
    }

    return true;
}

bool PShader::compileVertexShader() {
    glVertex = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(glVertex, 1, (const GLchar**)&vertSrc, 0);
    glCompileShader(this->glVertex);
    glGetShaderiv(this->glVertex, GL_COMPILE_STATUS, &IsCompiled_VS);

    if(this->IsCompiled_VS == false) {
        glGetShaderiv(this->glVertex, GL_INFO_LOG_LENGTH, &this->maxLength);
        char * vertexInfoLog = (char *)malloc(maxLength);
        glGetShaderInfoLog(glVertex, maxLength, &maxLength, vertexInfoLog);
        println(vertexInfoLog);
        free(vertexInfoLog);
        return false;
    }

    return true;
}