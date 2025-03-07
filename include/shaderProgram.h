#ifndef SHADER_PROGRAM_H 
#define SHADER_PROGRAM_H

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>

class Shader{
    public:
        GLuint ID;

        
        Shader(const char* Vertex_file, const char* Fragment_file);
        std::string get_file(const char* getfile);
        void useProgram();
        void deleteProgram();
};

#endif