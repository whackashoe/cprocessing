#include <GL/glew.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "cprocessing.hpp"
#include "pshader.hpp"

PShader::PShader() {
    init();
}

PShader::PShader(char * vertSrc, char * fragSrc) {
    init();
    this->setVertexShader(vertSrc);
    this->setFragmentShader(fragSrc); 
}


void PShader::init() {
    maxLength = 4096;
    IsCompiled_FS = 0;
    IsCompiled_VS = 0;
}


/* A simple function that will read a file into an allocated char pointer buffer */
char * PShader::filetobuf(char * src) {
    FILE *fptr;
    long length;
    char *buf;
     
    fptr = fopen(src, "rb"); /* Open file for reading */
    if (!fptr) return NULL;

    fseek(fptr, 0, SEEK_END); /* Seek to the end of the file */
    length = ftell(fptr); /* Find out how many bytes into the file we are */
    buf = (char*)malloc(length+1); /* Allocate a buffer for the entire length of the file and a null terminator */
    fseek(fptr, 0, SEEK_SET); /* Go back to the beginning of the file */
    ignore_size(fread(buf, length, 1, fptr)); /* Read the contents of the file in to the buffer */
    fclose(fptr); /* Close the file */
    buf[length] = 0; /* Null terminator */
   
    return buf; /* Return the buffer */
}


void PShader::setVertexShader(char * src) {
    this->vertSrc = filetobuf(src);
    compileVertexShader();
}

void PShader::setFragmentShader(char * src) {
    this->fragSrc = filetobuf(src);
    compileFragmentShader();
}

void PShader::bind() {

}

void PShader::unbind() {

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
   /* Create an empty fragment shader handle */
    glFragment = glCreateShader(GL_FRAGMENT_SHADER);
   
    /* Send the fragment shader source code to GL */
    /* Note that the source code is NULL character terminated. */
    /* GL will automatically detect that therefore the length info can be 0 in this case (the last parameter) */
    glShaderSource(glFragment, 1, (const GLchar**)&fragSrc, 0);
    glCompileShader(this->glFragment);
    glGetShaderiv(this->glFragment, GL_COMPILE_STATUS, &IsCompiled_FS);

    if(this->IsCompiled_FS == false) {
        glGetShaderiv(this->glFragment, GL_INFO_LOG_LENGTH, &this->maxLength);
        
        /* The maxLength includes the NULL character */
        char * fragmentInfoLog = (char *)malloc(maxLength);
        glGetShaderInfoLog(glFragment, maxLength, &maxLength, fragmentInfoLog);
        println(fragmentInfoLog);

        /* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
        /* In this simple program, we'll just leave */
        free(fragmentInfoLog);
        return false;
    } 

    return true;
}

bool PShader::compileVertexShader() {
   /* Create an empty fragment shader handle */
    glVertex = glCreateShader(GL_VERTEX_SHADER);
   
    /* Send the fragment shader source code to GL */
    /* Note that the source code is NULL character terminated. */
    /* GL will automatically detect that therefore the length info can be 0 in this case (the last parameter) */
    glShaderSource(glVertex, 1, (const GLchar**)&vertSrc, 0);
    glCompileShader(this->glVertex);
    glGetShaderiv(this->glVertex, GL_COMPILE_STATUS, &IsCompiled_VS);

    if(this->IsCompiled_VS == false) {
        glGetShaderiv(this->glVertex, GL_INFO_LOG_LENGTH, &this->maxLength);
        
        /* The maxLength includes the NULL character */
        char * vertexInfoLog = (char *)malloc(maxLength);
        glGetShaderInfoLog(glVertex, maxLength, &maxLength, vertexInfoLog);
        println(vertexInfoLog);

        /* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
        /* In this simple program, we'll just leave */
        free(vertexInfoLog);
        return false;
    } 

    return true;
}
