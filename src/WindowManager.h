//
// Created by Colby on 12/24/2019.
//

#ifndef BOILER_WINDOWMANAGER_H
#define BOILER_WINDOWMANAGER_H


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <memory>

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


class WindowManager {
private:
    inline static unsigned int WIDTH = 1280, HEIGHT = 720;
    inline static GLFWwindow* Window;

public:

    static void init(const std::string& windowName){
        if(!glfwInit())
            exit(-1);

        glfwSetErrorCallback(error_callback);

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // the window will stay hidden after creation
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif



        Window = glfwCreateWindow(WIDTH, HEIGHT, windowName.c_str(), nullptr, nullptr);

        if (!Window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetKeyCallback(Window, key_callback);

        glfwMakeContextCurrent(Window);

        glfwSwapInterval(1);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize OpenGL context" << std::endl;
            exit(-1);
        }

        int wBuffer = 0, hBuffer = 0;
        int *pWidth = &wBuffer, *pHeight = &hBuffer;
        glfwGetWindowSize(Window, pWidth, pHeight);
        const GLFWvidmode *videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());

        glfwSetWindowPos(
                Window,
                (videoMode->width - *pWidth) / 2,
                (videoMode->height - *pHeight) / 2
        );

        glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

        glfwShowWindow(Window);

    }

    static GLFWwindow* getWindow() { return WindowManager::Window; }


};

#endif //BOILER_WINDOWMANAGER_H
