#include "Core/input.h"

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

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

	void Input::processInput(Window* window, Camera* camera)
	{
		if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_W) == GLFW_PRESS)
		{
			camera->addCameraPosition(camera->getCameraSpeed() * camera->getFront());
		}

		if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_S) == GLFW_PRESS)
		{
			camera->addCameraPosition(-camera->getCameraSpeed() * camera->getFront());
		}

		if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_A) == GLFW_PRESS)
		{
			camera->addCameraPosition(normalize(cross(camera->getFront(), camera->getUp()) * -camera->getCameraSpeed()));
		}

		if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_D) == GLFW_PRESS)
		{
			camera->addCameraPosition(normalize(cross(camera->getFront(), camera->getUp()) * camera->getCameraSpeed()));
		}
	}
}