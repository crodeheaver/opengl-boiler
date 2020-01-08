//
// Created by Colby on 12/24/2019.
//

#ifndef BOILER_WINDOWMANAGER_H
#define BOILER_WINDOWMANAGER_H


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <memory>
#include "Camera.h"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

class WindowManager {
private:
    inline static unsigned int WIDTH = 1280, HEIGHT = 720;
    inline static bool firstMouse = true;
    inline static double lastX, lastY;
    inline static float deltaTime;
    inline static GLFWwindow* Window;
    inline static std::shared_ptr<Camera> camera;

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
    {
        camera->ProcessMouseScroll(yoffset);
    }

    static void mouse_callback(GLFWwindow* window, double xpos, double ypos)
    {
        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera->ProcessMouseMovement(xoffset, yoffset);
    }

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        // make sure the viewport matches the new window dimensions; note that width and
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }



public:

    static void setDeltaTime(float delta) { deltaTime = delta; }
    static void setLastX(double x) { lastX = x; }
    static void setLastY(double y) { lastX = y; }

    static void ProcessInput(GLFWwindow *window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera->ProcessKeyboard(FORWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera->ProcessKeyboard(BACKWARD, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera->ProcessKeyboard(LEFT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera->ProcessKeyboard(RIGHT, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
            camera->ProcessKeyboard(UP, deltaTime);
        if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
            camera->ProcessKeyboard(DOWN, deltaTime);
    }

    static void init(const std::string& windowName, std::shared_ptr<Camera> appCamera){
        if(!glfwInit())
            exit(-1);

        camera = appCamera;

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

        glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);
        glfwSetCursorPosCallback(Window, mouse_callback);
        glfwSetScrollCallback(Window, scroll_callback);

        // tell GLFW to capture our mouse
        glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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
