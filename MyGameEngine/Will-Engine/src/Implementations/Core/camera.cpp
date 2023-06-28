#include "Core/camera.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Enums/camera_movement_enum.h"
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

	Camera::Camera(Shader* shader, Window* window)
	{
		_window = window;

		_position = vec3(0.0f, 0.0f, 0.0f);

		_front = vec3(0.0f, 0.0f, -1.0f);

		_up = vec3(0.0f, 1.0f, 0.0f);

		_right = vec3(1.0f, 0.0f, 0.0f);

		_viewMatrix = mat4();

		_horizontalKeyboardInputEnum = CameraMovementEnum::NONE;

		_verticalKeyboardInputEnum = CameraMovementEnum::NONE;

		_viewMatrixLocation = shader->getUniformLocation("viewMatrix");

		_firstMouse = true;

		_lastMouseXPos = 0.0f;

		_lastMouseYPos = 0.0f;
		
		_mouseXPos = 0.0f;
		
		_mouseYPos = 0.0f;

		_yaw = 0.0f;

		_pitch = 0.0f;

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
		return _cameraMoveSpeed;
	}

	void Camera::updateViewMatrix()
	{
		_viewMatrix = lookAt(_position, _position + _front, _up);

		updateViewMatrixUniformData();
	}

	void Camera::inputCameraMovement()
	{
		if (Input::isKeyPressed(_window, GLFW_KEY_W))
		{
			_horizontalKeyboardInputEnum = CameraMovementEnum::FORWARD;
		}
		else if (Input::isKeyPressed(_window, GLFW_KEY_S))
		{
			_horizontalKeyboardInputEnum = CameraMovementEnum::BACKWARD;
		}
		else
		{
			_horizontalKeyboardInputEnum = CameraMovementEnum::NONE;
		}		

		if (Input::isKeyPressed(_window, GLFW_KEY_A))
		{
			_verticalKeyboardInputEnum = CameraMovementEnum::LEFT;
		}
		else if (Input::isKeyPressed(_window, GLFW_KEY_D))
		{
			_verticalKeyboardInputEnum = CameraMovementEnum::RIGHT;
		}
		else
		{
			_verticalKeyboardInputEnum = CameraMovementEnum::NONE;
		}
	}

	void Camera::updateCameraMovement()
	{
		updateCameraKeyboardMovement();

		updateCameraMouseMovement();
	}

	void Camera::updateCameraKeyboardMovement()
	{
		switch (_horizontalKeyboardInputEnum)
		{
		case CameraMovementEnum::FORWARD:

			addCameraPosition(getCameraSpeed() * getFront() * DeltaTime::getDeltaTime());
			
			break;
		case CameraMovementEnum::BACKWARD:
			
			addCameraPosition(-getCameraSpeed() * getFront() * DeltaTime::getDeltaTime());
					
			break;
		case CameraMovementEnum::NONE:
			break;
		default:
			break;
		}

		switch (_verticalKeyboardInputEnum)
		{
		case CameraMovementEnum::LEFT:

			addCameraPosition(normalize(cross(getFront(), getUp()) * -getCameraSpeed() * DeltaTime::getDeltaTime()));

			break;
		case CameraMovementEnum::RIGHT:			
			
			addCameraPosition(normalize(cross(getFront(), getUp()) * getCameraSpeed() * DeltaTime::getDeltaTime()));
			
			break;
		case CameraMovementEnum::NONE:
			break;
		default:
			break;
		}
	}

	void Camera::updateCameraMouseMovement()
	{
		Input::mousePosition(_window, _mouseXPos, _mouseYPos);

		if (_firstMouse)
		{
			_lastMouseXPos = _mouseXPos;
			_lastMouseYPos = _mouseYPos;

			_firstMouse = false;
		}

		float xoffset = _mouseXPos - _lastMouseXPos;
		float yoffset = _lastMouseYPos - _mouseYPos;

		_lastMouseXPos = _mouseXPos;
		_lastMouseYPos = _mouseYPos;		

		xoffset *= _cameraMouseSensitivity;
		yoffset *= _cameraMouseSensitivity;

		_yaw += xoffset;
		_pitch += yoffset;

		if (_pitch > 89.0f)
		{
			_pitch = 89.0f;
		}

		if (_pitch < -89.0f)
		{
			_pitch = -89.0f;
		}

		vec3 direction;

		direction.x = cos(radians(_yaw)) * cos(radians(_pitch));

		direction.y = sin(radians(_pitch));

		direction.z = sin(radians(_yaw)) * cos(radians(_pitch));

		_front = normalize(direction);
	}
}