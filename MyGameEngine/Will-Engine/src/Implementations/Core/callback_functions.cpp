#include "Core/callback_functions.h"

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

using namespace glm;

namespace WillEngine
{
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}	
}