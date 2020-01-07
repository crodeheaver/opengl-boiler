//
// Created by Colby on 1/6/2020.
//

#ifndef BOILER_MATHS_H
#define BOILER_MATHS_H

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

class Maths {
public:
    static glm::mat4 createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale){
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(translation.x, translation.y, translation.z));
        //trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(rx, ry, rz));
        trans = glm::rotate(trans, glm::radians(rx), glm::vec3(1, 0, 0));
        trans = glm::rotate(trans, glm::radians(ry), glm::vec3(0, 1, 0));
        trans = glm::rotate(trans, glm::radians(rz), glm::vec3(1, 0, 1));

        trans = glm::scale(trans, glm::vec3(scale,scale,scale));

        return trans;
    }
};

#endif //BOILER_MATHS_H
