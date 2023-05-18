#include <glew.h>
#include <glfw3.h>

int main(void)
{
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //This set the Opengl "Right part" Version: this is v3.x 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //This set the Opengl "Left part" Version: this is v3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Encourages the use of modern OpenGL    

    return 0;
}