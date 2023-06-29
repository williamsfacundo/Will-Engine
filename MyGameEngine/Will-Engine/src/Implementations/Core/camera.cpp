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

		_position = WorldOrigin;

		_right = WorldRight;

		_up = WorldUp;

		_front = WorldFront;

		_lookDirection = vec3();

		_viewMatrix = mat4();

		_horizontalKeyboardInputEnum = CameraMovementEnum::NONE;

		_verticalKeyboardInputEnum = CameraMovementEnum::NONE;

		_viewMatrixLocation = shader->getUniformLocation("viewMatrix");		

		_mouseXPos = 0.0f;
		_mouseYPos = 0.0f;

		_lastMouseXPos = 0.0f;
		_lastMouseYPos = 0.0f;			

		_mouseXOffset = 0.0f;
		_mouseYOffset = 0.0f;

		_yaw = 0.0f;

		_pitch = 0.0f;

		_shouldUpdateViewMatrix = true;

		_firstMouse = true;

		if (_viewMatrixLocation == -1)
		{
			cout << "Could not find the view matrix uniform location!\n" << endl;
		}	

		updateViewMatrix();
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
		if(_shouldUpdateViewMatrix)
		{
			_lookDirection = _position + _front;

			_viewMatrix = lookAt(_position, _position + _front, _up);		

			updateViewMatrixUniformData();

			_shouldUpdateViewMatrix = false;
		}
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

			addCameraPosition(getFront() * getCameraSpeed() * DeltaTime::getDeltaTime());
			
			break;
		case CameraMovementEnum::BACKWARD:
			
			addCameraPosition(getFront() * -getCameraSpeed() * DeltaTime::getDeltaTime());
					
			break;
		case CameraMovementEnum::NONE:
			break;
		default:
			break;
		}

		switch (_verticalKeyboardInputEnum)
		{
		case CameraMovementEnum::LEFT:

			addCameraPosition(-_right * getCameraSpeed() * DeltaTime::getDeltaTime());

			break;
		case CameraMovementEnum::RIGHT:			
			
			addCameraPosition(_right * getCameraSpeed() * DeltaTime::getDeltaTime());
			
			break;
		case CameraMovementEnum::NONE:
			break;
		default:
			break;
		}

		if (_horizontalKeyboardInputEnum != CameraMovementEnum::NONE || _verticalKeyboardInputEnum != CameraMovementEnum::NONE)
		{
			_shouldUpdateViewMatrix = true;
		}
	}

	void Camera::updateCameraMouseMovement()
	{
		Input::mousePosition(_window, _mouseXPos, _mouseYPos);

		if(_firstMouse)
		{
			_lastMouseXPos = _mouseXPos;
			_lastMouseYPos = _mouseYPos;

			_firstMouse = false;
		}

		_mouseXOffset = static_cast<float>(_mouseXPos - _lastMouseXPos);
		_mouseYOffset = static_cast<float>(_lastMouseYPos - _mouseYPos);
		
		_lastMouseXPos = _mouseXPos;
		_lastMouseYPos = _mouseYPos;

		if(_mouseXOffset != 0.0f || _mouseYOffset != 0.0f)
		{
			_mouseXOffset *= _cameraMouseSensitivity;
			_mouseYOffset *= _cameraMouseSensitivity;

			_yaw += _mouseXOffset;
			_pitch += _mouseYOffset;

			if (_pitch > 89.0f)
			{
				_pitch = 89.0f;
			}

			if (_pitch < -89.0f)
			{
				_pitch = -89.0f;
			}			

			_front.x = cos(radians(_yaw)) * cos(radians(_pitch));

			_front.y = sin(radians(_pitch));

			_front.z = sin(radians(_yaw)) * cos(radians(_pitch));

			_front = normalize(_front);

			_right = normalize(cross(_front, WorldUp));

			_up = normalize(cross(_right, _front));

			if(!_shouldUpdateViewMatrix)
			{
				_shouldUpdateViewMatrix = true;
			}
		}			
	}
}