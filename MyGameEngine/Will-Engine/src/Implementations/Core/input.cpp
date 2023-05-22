#include "Core/input.h"

#include <glew.h>
#include <glfw3.h>

namespace WillEngine
{
	Input::Input()
	{

	}

	Input::~Input()
	{

	}

	void Input::processInput(Window* window)
	{
		if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window->getGLFWwindow(), true);
		}
	}
}