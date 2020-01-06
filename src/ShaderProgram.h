//
// Created by colby on 12/9/19.
//

#ifndef BOILER_SHADERPROGRAM_H
#define BOILER_SHADERPROGRAM_H


#include <string>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <memory>

enum class ShaderType {
    NONE = -1,
    VERTEX = 0,
    FRAGMENT = 1
};

class ShaderProgram {
private:

protected:
    unsigned int programId;
    unsigned int vertexShaderId;
    unsigned int fragmentShaderId;

    void LoadShader(const std::string& fileName);

    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);


public:
    ShaderProgram(const std::string& fileName);
    ~ShaderProgram();
    unsigned int getUniformLocation(const std::string& uniformName);
    void bindAttribute(unsigned int attribute, const std::string& variableName);
    void loadInt(unsigned int location, unsigned int value);
    void loadFloat(unsigned int location, float value);
    void loadVector(unsigned int location, glm::vec3 vector);
    void loadBoolean(unsigned int location, bool value);
    void loadMatrix(unsigned int location, std::shared_ptr<glm::mat4> matrix);
    void start();
    void stop();
};


#endif //VOX_SHADERPROGRAM_H
