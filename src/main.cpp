#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include "ShaderProgram.h"
#include "TextureLoader.h"
#include "WindowManager.h"
#include "Maths.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    WindowManager::init("Boiler");

    auto window = WindowManager::getWindow();

    ShaderProgram program("shader");



    float vertices[] = {
            -0.5f,0.5f,-0.5f,   0,0,
            -0.5f,-0.5f,-0.5f,  0,1,
            0.5f,-0.5f,-0.5f,   1,1,
            0.5f,0.5f,-0.5f,    1,0,

            -0.5f,0.5f,0.5f,    0,0,
            -0.5f,-0.5f,0.5f,   0,1,
            0.5f,-0.5f,0.5f,    1,1,
            0.5f,0.5f,0.5f,     1,0,

            0.5f,0.5f,-0.5f,    0,0,
            0.5f,-0.5f,-0.5f,   0,1,
            0.5f,-0.5f,0.5f,    1,1,
            0.5f,0.5f,0.5f,     1,0,

            -0.5f,0.5f,-0.5f,   0,0,
            -0.5f,-0.5f,-0.5f,  0,1,
            -0.5f,-0.5f,0.5f,   1,1,
            -0.5f,0.5f,0.5f,    1,0,

            -0.5f,0.5f,0.5f,    0,0,
            -0.5f,0.5f,-0.5f,   0,1,
            0.5f,0.5f,-0.5f,    1,1,
            0.5f,0.5f,0.5f,     1,0,

            -0.5f,-0.5f,0.5f,   0,0,
            -0.5f,-0.5f,-0.5f,  0,1,
            0.5f,-0.5f,-0.5f,   1,1,
            0.5f,-0.5f,0.5f,    1,0
    };
    unsigned int indices[] = {
            0,1,3,
            3,1,2,
            4,5,7,
            7,5,6,
            8,9,11,
            11,9,10,
            12,13,15,
            15,13,14,
            16,17,19,
            19,17,18,
            20,21,23,
            23,21,22
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    TextureLoader texture("texture");

    float rotation = 0;


    glm::mat4 view = glm::mat4(1.0f);
// note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // render container
        program.start();

        auto translation = glm::vec3(-0.25f, 0.0f, 0.0f);

        auto trans = Maths::createTransformationMatrix(translation, rotation,rotation,0,.5);

        unsigned int transformLoc = program.getUniformLocation("model");
        unsigned int viewLoc = program.getUniformLocation("view");
        unsigned int perspectiveLoc = program.getUniformLocation("perspective");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        // These are the steps needed to create a new square
        translation = glm::vec3(0.25f, 0.0f, 0.0f);
        trans = Maths::createTransformationMatrix(translation, rotation,rotation,0,.5);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
        rotation += .2;
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);


    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}