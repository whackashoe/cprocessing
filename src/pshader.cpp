#include "cprocessing.hpp"

PShader::PShader() : maxLength(4096), IsCompiled_FS(0), IsCompiled_VS(0), glProgram(glCreateProgram()) {
    assert(initialized);
}

PShader::PShader(std::string vertSrc, std::string fragSrc) : maxLength(4096), IsCompiled_FS(0), IsCompiled_VS(0), glProgram(glCreateProgram()) {
    assert(initialized);
    this->setVertexShader(vertSrc);
    this->setFragmentShader(fragSrc);
}

PShader::~PShader() {
    glDeleteProgram(glProgram);
    if(IsCompiled_VS) glDeleteShader(glVertex);
    if(IsCompiled_FS) glDeleteShader(glFragment);
}

void PShader::setVertexShader(std::string src) {
    vertSrc=src;
    compileVertexShader();
    glAttachShader(glProgram, glVertex);
    glLinkProgram(glProgram);
}

void PShader::setFragmentShader(std::string src) {
    fragSrc = src;
    compileFragmentShader();
    glAttachShader(glProgram, glFragment);
    glLinkProgram(glProgram);
}

void PShader::loadVertexShader(std::string src) {
    this->vertSrc = loadBytes(src);
    compileVertexShader();
    glAttachShader(glProgram, glVertex);
    glLinkProgram(glProgram);
}

void PShader::loadFragmentShader(std::string src) {
    this->fragSrc = loadBytes(src);
    compileFragmentShader();
    glAttachShader(glProgram, glFragment);
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

void PShader::setUniform(std::string name, GLfloat value) {
    glUniform1f(glGetUniformLocation(glProgram, name.c_str()), value);
}

void PShader::setUniform(std::string name, GLfloat v0, GLfloat v1) {
    glUniform2f(glGetUniformLocation(glProgram, name.c_str()), v0, v1);
}

void PShader::setUniform(std::string name, GLfloat v0, GLfloat v1, GLfloat v2) {
    glUniform3f(glGetUniformLocation(glProgram, name.c_str()), v0, v1, v2);
}

void PShader::setUniform(std::string name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    glUniform4f(glGetUniformLocation(glProgram, name.c_str()), v0, v1, v2, v3);
}

void PShader::setUniform(std::string name, GLint value) {
    glUniform1i(glGetUniformLocation(glProgram, name.c_str()), value);
}

void PShader::setUniform(std::string name, GLint v0, GLint v1) {
    glUniform2i(glGetUniformLocation(glProgram, name.c_str()), v0, v1);
}

void PShader::setUniform(std::string name, GLint v0, GLint v1, GLint v2) {
    glUniform3i(glGetUniformLocation(glProgram, name.c_str()), v0, v1, v2);
}

void PShader::setUniform(std::string name, GLint v0, GLint v1, GLint v2, GLint v3) {
    glUniform4i(glGetUniformLocation(glProgram, name.c_str()), v0, v1, v2, v3);
}

void PShader::setUniformMatrix2(std::string name, const GLfloat * v) {
    glUniformMatrix2fv(glGetUniformLocation(glProgram, name.c_str()), 1, false, v);
}
void PShader::setUniformMatrix3(std::string name, const GLfloat * v) {
    glUniformMatrix3fv(glGetUniformLocation(glProgram, name.c_str()), 1, false, v);

}
void PShader::setUniformMatrix4(std::string name, const GLfloat * v) {
    glUniformMatrix4fv(glGetUniformLocation(glProgram, name.c_str()), 1, false, v);
}


void PShader::setAttribute(std::string name, GLfloat value) {
    glVertexAttrib1f(glGetAttribLocation(glProgram, name.c_str()), value);
}

void PShader::setAttribute(std::string name, GLfloat v0, GLfloat v1) {
    glVertexAttrib2f(glGetAttribLocation(glProgram, name.c_str()), v0, v1);
}

void PShader::setAttribute(std::string name, GLfloat v0, GLfloat v1, GLfloat v2) {
    glVertexAttrib3f(glGetAttribLocation(glProgram, name.c_str()), v0, v1, v2);
}

void PShader::setAttribute(std::string name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    glVertexAttrib4f(glGetAttribLocation(glProgram, name.c_str()), v0, v1, v2, v3);
}

void PShader::setAttribute(std::string name, GLint value) {
    glVertexAttribI1i(glGetAttribLocation(glProgram, name.c_str()), value);
}

void PShader::setAttribute(std::string name, GLint v0, GLint v1) {
    glVertexAttribI2i(glGetAttribLocation(glProgram, name.c_str()), v0, v1);
}

void PShader::setAttribute(std::string name, GLint v0, GLint v1, GLint v2) {
    glVertexAttribI3i(glGetAttribLocation(glProgram, name.c_str()), v0, v1, v2);
}

void PShader::setAttribute(std::string name, GLint v0, GLint v1, GLint v2, GLint v3) {
    glVertexAttribI4i(glGetAttribLocation(glProgram, name.c_str()), v0, v1, v2, v3);
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
        char * fragmentInfoLog = (char *)malloc(sizeof(char)*maxLength);
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
        char * vertexInfoLog = (char *)malloc(sizeof(char)*maxLength);
        glGetShaderInfoLog(glVertex, maxLength, &maxLength, vertexInfoLog);
        println(vertexInfoLog);
        free(vertexInfoLog);
        return false;
    }

    return true;
}