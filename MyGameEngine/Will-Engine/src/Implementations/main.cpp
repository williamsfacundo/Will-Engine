#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"

using namespace WillEngine;

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

    if (window != nullptr) 
    { 
        delete window; 
    }

    return 0;
}