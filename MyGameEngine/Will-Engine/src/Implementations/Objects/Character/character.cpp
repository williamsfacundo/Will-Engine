#include "Objects/Character/character.h"

#include "Core/window.h"
#include "Objects/object.h"
#include "Objects/Character/movement_controller.h"
#include "Objects/Character/look_around_controller.h"
#include "Core/Camera/camera.h"

namespace WillEngine
{
	Character::Character(Window* window, Camera* characterCamera, Shader* objectShader) : Object(objectShader)
	{
		setFirstPersonView(true);
		
		_characterCamera = characterCamera;

		if(_firstPersonView)
		{
			_movementController = new MovementController(window, getObjectTransform(), _characterCamera->getCameraTransform());

			_lookAroundController = new LookAroundController(window, _characterCamera->getCameraTransform());
		}
	}
	
	Character::~Character()
	{
		if(_movementController != nullptr)
		{
			delete _movementController;
		}

		if(_lookAroundController != nullptr)
		{
			delete _lookAroundController;
		}
	}

	void Character::setFirstPersonView(bool value)
	{
		_firstPersonView = value;
	}

	MovementController* Character::getMovementController()
	{
		return _movementController;
	}

	LookAroundController* Character::getLookAroundController()
	{
		return _lookAroundController;
	}

	void Character::setData()
	{

	}

	int Character::getAmountOfIndexes()
	{
		return 0;
	}
}