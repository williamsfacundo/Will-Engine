#include "Objects/Character/look_around_controller.h"

#include "Core/input.h"

namespace WillEngine
{
	LookAroundController::LookAroundController(Window* window, Transform* cameraTransform)
	{
		_window = window;

		_cameraTransform = cameraTransform;

		_mouseSensitivity = DefaultMouseSensitivity;

		_mouseXPos = 0.0f;
		_mouseYPos = 0.0f;

		_lastMouseXPos = 0.0f;
		_lastMouseYPos = 0.0f;

		_mouseXOffset = 0.0f;
		_mouseYOffset = 0.0f;

		_cameraTransform->setLocalRotationY(-90);

		_firstMouse = true;
	}

	LookAroundController::~LookAroundController()
	{

	}

	void LookAroundController::setMouseSensitivity(float mouseSensitivity)
	{
		_mouseSensitivity = mouseSensitivity;
	}

	float LookAroundController::getMouseSensitivity()
	{
		return _mouseSensitivity;
	}

	void LookAroundController::update()
	{
		Input::mousePosition(_window, _mouseXPos, _mouseYPos);

		if (_firstMouse)
		{
			_lastMouseXPos = _mouseXPos;
			_lastMouseYPos = _mouseYPos;

			_firstMouse = false;
		}

		_mouseXOffset = static_cast<float>(_mouseXPos - _lastMouseXPos);
		_mouseYOffset = static_cast<float>(_lastMouseYPos - _mouseYPos);

		_lastMouseXPos = _mouseXPos;
		_lastMouseYPos = _mouseYPos;

		if (_mouseXOffset != 0.0f || _mouseYOffset != 0.0f)
		{
			_mouseXOffset *= _mouseSensitivity;
			_mouseYOffset *= _mouseSensitivity;			

			//_yaw += _mouseXOffset;
			//_pitch += _mouseYOffset;

			_cameraTransform->addLocalXRotation(_mouseYOffset);
			_cameraTransform->addLocalYRotation(_mouseXOffset);

			/*if (_pitch > 89.0f)
			{
				_pitch = 89.0f;
			}

			if (_pitch < -89.0f)
			{
				_pitch = -89.0f;
			}*/

			if(_cameraTransform->getLocalRotation().x > 89.0f)
			{
				_cameraTransform->setLocalRotationX(89.0f);
			}

			if (_cameraTransform->getLocalRotation().x < -89.0f)
			{
				_cameraTransform->setLocalRotationX(-89.0f);
			}

			/*_front.x = cos(radians(_yaw)) * cos(radians(_pitch));

			_front.y = sin(radians(_pitch));

			_front.z = sin(radians(_yaw)) * cos(radians(_pitch));

			_front = normalize(_front);

			_right = normalize(cross(_front, WorldUp));

			_up = normalize(cross(_right, _front));*/

			//x(pitch), y(yaw), z(roll)

			_cameraTransform->setLocalFrontX(cos(radians(_cameraTransform->getLocalRotation().y)) * cos(radians(_cameraTransform->getLocalRotation().x)));
			_cameraTransform->setLocalFrontY(sin(radians(_cameraTransform->getLocalRotation().y)));
			_cameraTransform->setLocalFrontZ(sin(radians(_cameraTransform->getLocalRotation().y)) * cos(radians(_cameraTransform->getLocalRotation().x)));
			_cameraTransform->setLocalFront(normalize(_cameraTransform->getLocalFront()));
			
			_cameraTransform->setLocalRight(normalize(cross(_cameraTransform->getLocalFront(), _cameraTransform->getWorldUp())));
			
			_cameraTransform->setLocalUp(normalize(cross(_cameraTransform->getLocalRight(), _cameraTransform->getLocalFront())));
		}
	}
}