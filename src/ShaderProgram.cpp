//
// Created by colby on 12/9/19.
//

#include <glad/glad.h>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include <array>
#include <fstream>
#include <sstream>
#include "ShaderProgram.h"
ShaderProgram::ShaderProgram(const std::string& fileName) {
    LoadShader("../res/shaders/" + fileName + ".glsl");
}

void ShaderProgram::LoadShader(const std::string& fileName) {
    std::ifstream stream(fileName);

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else {
            ss[(int)type] << line << '\n';
        }
    }

    auto vertexShader = ss[0].str();
    auto fragmentShader = ss[1].str();
    programId = CreateShader(vertexShader,fragmentShader);
}

unsigned int ShaderProgram::CreateShader(const std::string &vertexShader, const std::string &fragmentShader) {
    programId = glCreateProgram();
    vertexShaderId = CompileShader(GL_VERTEX_SHADER, vertexShader);
    fragmentShaderId = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);

    //this->bindAttributes();

    glLinkProgram(programId);
    glValidateProgram(programId);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    //getAllUniformLocations();
    return programId;
}

unsigned int ShaderProgram::CompileShader(unsigned int type, const std::string &source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int result;

    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)malloc(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

ShaderProgram::~ShaderProgram() {
    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    glDeleteProgram(programId);
}

unsigned int ShaderProgram::getUniformLocation(const std::string &uniformName) {
    return glGetUniformLocation(programId, uniformName.c_str());
}

void ShaderProgram::bindAttribute(unsigned int attribute, const std::string &variableName) {
    glBindAttribLocation(programId, attribute, variableName.c_str());
}

void ShaderProgram::loadInt(unsigned int location, unsigned int value) {
    glUniform1i(location, value);
}

void ShaderProgram::loadFloat(unsigned int location, float value) {
    glUniform1f(location, value);
}

void ShaderProgram::loadVector(unsigned int location, glm::vec3 vector) {
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void ShaderProgram::loadBoolean(unsigned int location, bool value) {
    glUniform1f(location, value ? 1 : 0);
}

void ShaderProgram::loadMatrix(unsigned int location, std::shared_ptr<glm::mat4> matrix) {
    auto mat = glm::value_ptr(*matrix);
    glUniformMatrix4fv(location, 1, GL_FALSE, mat);
}

void ShaderProgram::start() {
    glUseProgram(programId);
}

void ShaderProgram::stop() {
    glUseProgram(0);
}


