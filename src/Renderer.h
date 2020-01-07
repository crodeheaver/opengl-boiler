//
// Created by Colby on 1/7/2020.
//

#ifndef BOILER_RENDERER_H
#define BOILER_RENDERER_H
#include <iostream>
#include <glad/glad.h>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))


void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "):" << function << " " << file << " " << line  << std::endl;
        return false;
    }
    return true;
}

#endif //BOILER_RENDERER_H
