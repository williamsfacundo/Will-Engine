#include "Core/renderer.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Shaders/shader.h"
#include "Objects/object.h"

using namespace std;

namespace WillEngine
{
	void Renderer::updateProjectionMatrixUniformData()
	{
		glUniformMatrix4fv(_projectionMatrixLocation, 1, GL_FALSE, value_ptr(_projectionMatrix));
	}

	Renderer::Renderer(Shader* shader)
	{
		_projectionMatrix = perspective(radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		_projectionMatrixLocation = shader->getUniformLocation("projectionMatrix");

		if (_projectionMatrixLocation == -1)
		{
			cout << "Could not find the projection matrix uniform location!\n" << endl;
		}
		else
		{
			shader->useShaderProgram();

			updateProjectionMatrixUniformData();

			glUseProgram(0);
		}
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

		//camera->updateViewMatrixUniformData();		

		object->getTexture()->selectTexture();

		object->selectObject();

		glDrawElements(GL_TRIANGLES, object->getAmountOfIndexes(), GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glUseProgram(0);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
}