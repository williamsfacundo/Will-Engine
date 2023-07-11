#include "Core/Camera/camera.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Core/delta_time.h"
#include "Shaders/shader.h"
#include "Core/input.h"

using namespace std;

namespace WillEngine
{
	void Camera::updateViewMatrixUniformData()
	{
		glUniformMatrix4fv(_viewMatrixLocation, 1, GL_FALSE, value_ptr(_viewMatrix));
	}

	Camera::Camera(Shader* shader)
	{
		_cameraTransform = new Transform();
		
		_viewMatrix = mat4();		

		_viewMatrixLocation = shader->getUniformLocation("viewMatrix");				

		if (_viewMatrixLocation == -1)
		{
			cout << "Could not find the view matrix uniform location!\n" << endl;
		}	

		updateViewMatrix();
	}

	Camera::~Camera()
	{

	}	

	void Camera::updateViewMatrix()
	{
		_viewMatrix = lookAt(
			_cameraTransform->getLocalPosition(), 
			_cameraTransform->getLocalPosition() + _cameraTransform->getLocalFront(), 
			_cameraTransform->getLocalUp());

		updateViewMatrixUniformData();		
	}

	Transform* Camera::getCameraTransform()
	{
		return _cameraTransform;
	}
}