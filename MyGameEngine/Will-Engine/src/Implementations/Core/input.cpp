#include "Core/input.h"

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

#include "Core/delta_time.h"

using namespace glm;

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

	bool Input::isKeyPressed(Window* window, int key)
	{
		return (glfwGetKey(window->getGLFWwindow(), key) == GLFW_PRESS);
	}

	void Input::mousePosition(Window* window, double& xPos, double& yPos)
	{
		glfwGetCursorPos(window->getGLFWwindow(), &xPos, &yPos);
	}
}