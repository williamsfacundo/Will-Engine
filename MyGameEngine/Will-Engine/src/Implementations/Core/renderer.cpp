#include "Core/renderer.h"

#include <glew.h>
#include <glfw3.h>

namespace WillEngine
{
	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{

	}

	void Renderer::renderingCommands()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);
	}
}