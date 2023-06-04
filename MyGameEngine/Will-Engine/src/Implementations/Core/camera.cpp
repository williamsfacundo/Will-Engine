#include "Core/camera.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Shaders/shader.h"

using namespace std;

namespace WillEngine
{
	void Camera::updateViewMatrixUniformData()
	{
		glUniformMatrix4fv(_viewMatrixLocation, 1, GL_FALSE, value_ptr(_viewMatrix));
	}

	Camera::Camera(Shader* shader)
	{
		_viewMatrix = mat4(1.0f);
		
		_viewMatrix = translate(_viewMatrix, vec3(0.0f, 0.0f, -3.0f));

		_viewMatrixLocation = shader->getUniformLocation("viewMatrix");

		if (_viewMatrixLocation == -1)
		{
			cout << "Could not find the view matrix uniform location!\n" << endl;
		}
		else
		{
			shader->useShaderProgram();

			updateViewMatrixUniformData();

			glUseProgram(0);
		}
	}

	Camera::~Camera()
	{

	}
}