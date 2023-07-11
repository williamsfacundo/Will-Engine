#include "Objects/Character/movement_controller.h"

#include "Core/input.h"
#include "Core/delta_time.h"

namespace WillEngine
{
	MovementController::MovementController(Window* window, ObjectTransform* characterTransform, Transform* cameraTransform)
	{
		_window = window;

		_characterTransform = characterTransform;

		_cameraTransform = cameraTransform;

		_moveSpeed = DefaultMoveSpeed;

		setInputKeysToDefault();		
	}

	MovementController::MovementController(Window* window, ObjectTransform* characterTransform, Transform* cameraTransform, float moveSpeed)
	{
		_window = window;

		_characterTransform = characterTransform;

		_cameraTransform = cameraTransform;

		_moveSpeed = moveSpeed;

		setInputKeysToDefault();
	}
	
	MovementController::~MovementController()
	{

	}

	void MovementController::setMoveSpeed(float moveSpeed)
	{
		_moveSpeed = moveSpeed;
	}	

	void MovementController::setMoveForwardKey(int newKey)
	{
		_moveForwardKey = newKey;
	}

	void MovementController::setMoveBackwardKey(int newKey)
	{
		_moveBackwardKey = newKey;
	}
	
	void MovementController::setMoveRightKey(int newKey)
	{
		_moveRightKey = newKey;
	}
	
	void MovementController::setMoveLeftKey(int newKey)
	{
		_moveLeftKey = newKey;
	}

	void MovementController::setInputKeysToDefault()
	{
		_moveForwardKey = DefaultMoveForwardKey;

		_moveBackwardKey = DefaultMoveBackwardKey;

		_moveRightKey = DefaultMoveRightKey;

		_moveLeftKey = DefaultMoveLeftKey;
	}

	float MovementController::getMoveSpeed()
	{
		return _moveSpeed;
	}

	bool MovementController::getMoveInputDetected()
	{
		return _moveInputDetected;
	}

	void MovementController::input()
	{
		if (Input::isKeyPressed(_window, GLFW_KEY_W))
		{
			_horizontalKeyboardInput = MovementEnum::FORWARD;
		}
		else if (Input::isKeyPressed(_window, GLFW_KEY_S))
		{
			_horizontalKeyboardInput = MovementEnum::BACKWARD;
		}
		else
		{
			_horizontalKeyboardInput = MovementEnum::NONE;
		}

		if (Input::isKeyPressed(_window, GLFW_KEY_A))
		{
			_verticalKeyboardInput = MovementEnum::LEFT;
		}
		else if (Input::isKeyPressed(_window, GLFW_KEY_D))
		{
			_verticalKeyboardInput = MovementEnum::RIGHT;
		}
		else
		{
			_verticalKeyboardInput = MovementEnum::NONE;
		}

		if (_horizontalKeyboardInput == MovementEnum::NONE && _verticalKeyboardInput == MovementEnum::NONE)
		{
			_moveInputDetected = false;
		}
		else
		{
			_moveInputDetected = true;
		}
	}

	void MovementController::update()
	{
		if (_moveInputDetected)
		{
			switch (_horizontalKeyboardInput)
			{
			case MovementEnum::FORWARD:

				_characterTransform->addLocalPosition(_cameraTransform->getLocalFront() * _moveSpeed * DeltaTime::getDeltaTime());
								
				break;
			case MovementEnum::BACKWARD:

				_characterTransform->addLocalPosition(-_cameraTransform->getLocalFront() * _moveSpeed * DeltaTime::getDeltaTime());

				break;
			case MovementEnum::NONE:
				break;
			default:
				break;
			}

			switch (_verticalKeyboardInput)
			{
			case MovementEnum::LEFT:

				_characterTransform->addLocalPosition(-_cameraTransform->getLocalRight() * _moveSpeed * DeltaTime::getDeltaTime());

				break;
			case MovementEnum::RIGHT:

				_characterTransform->addLocalPosition(_cameraTransform->getLocalRight() * _moveSpeed * DeltaTime::getDeltaTime());

				break;
			case MovementEnum::NONE:
				break;
			default:
				break;
			}

			_cameraTransform->setLocalPosition(_characterTransform->getLocalPosition());
		}				
	}
}