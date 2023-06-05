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
		_position = vec3(0.0f, 0.0f, 0.0f);

		_front = vec3(0.0f, 0.0f, -1.0f);

		_up = vec3(0.0f, 1.0f, 0.0f);

		_right = vec3(1.0f, 0.0f, 0.0f);

		_viewMatrix = mat4();

		_viewMatrixLocation = shader->getUniformLocation("viewMatrix");

		if (_viewMatrixLocation == -1)
		{
			cout << "Could not find the view matrix uniform location!\n" << endl;
		}		
	}

	Camera::~Camera()
	{

	}

	void Camera::addCameraPosition(vec3 value)
	{
		_position += value;
	}

	vec3 Camera::getFront()
	{
		return _front;
	}

	vec3 Camera::getUp()
	{
		return _up;
	}

	float Camera::getCameraSpeed() 
	{
		return _cameraSpeed;
	}

	void Camera::updateViewMatrix()
	{
		_viewMatrix = lookAt(_position, _position + _front, _up);

		updateViewMatrixUniformData();
	}
}