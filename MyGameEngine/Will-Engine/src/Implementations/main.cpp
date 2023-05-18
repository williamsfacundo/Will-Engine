#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"

using namespace WillEngine;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void renderLoop(Window* window);

void processInput(GLFWwindow* window);

void RenderingCommands();

int main(void)
{
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //This set the Opengl "Right part" Version: this is v3.x 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //This set the Opengl "Left part" Version: this is v3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Encourages the use of modern OpenGL 

    Window* window = new Window();

    bool windowInitSuccessfully = window->initWindow();

    if(!windowInitSuccessfully)
    {
        return -2;
    }

    window->createValidOpenglContext();
        
    if (GLEW_OK != glewInit())
    {
        return -3;
    }

    glfwSetFramebufferSizeCallback(window->getGLFWwindow(), framebuffer_size_callback);

    renderLoop(window);

    if (window != nullptr) 
    { 
        delete window; 
    }

    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void renderLoop(Window* window)
{
    while (!glfwWindowShouldClose(window->getGLFWwindow()))
    {
        //Input
        processInput(window->getGLFWwindow());

        //Rendering
        RenderingCommands();

        glfwSwapBuffers(window->getGLFWwindow());

        glfwPollEvents();
    }
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void RenderingCommands()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);
}