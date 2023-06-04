#include "Core/renderer.h"

#include <glew.h>
#include <glfw3.h>

#include "Shaders/shader.h"
#include "Objects/object.h"

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

	void Renderer::drawObject(Object* object, Camera* camera)
	{
		object->getShader()->useShaderProgram();

		object->getTransform()->updateModelMatrix();		

		object->getTexture()->selectTexture();

		object->selectObject();

		camera->updateViewMatrixUniformData();

		glDrawElements(GL_TRIANGLES, object->getAmountOfIndexes(), GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glUseProgram(0);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
}