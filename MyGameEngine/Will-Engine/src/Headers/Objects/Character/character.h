#ifndef CHARACTER_H
#define CHARACTER_H

#include "Core/window.h"
#include "Objects/object.h"
#include "movement_controller.h"
#include "look_around_controller.h"
#include "Core/Camera/camera.h"

namespace WillEngine
{
	class Character : public Object
	{
	private:
		MovementController* _movementController;		
		LookAroundController* _lookAroundController;

		Camera* _characterCamera;

		bool _firstPersonView;

	public:
		Character(Window* window, Camera* characterCamera, Shader* objectShader);
		~Character();

		void setFirstPersonView(bool value);

		MovementController* getMovementController();

		LookAroundController* getLookAroundController();
		
		void setData();

		int getAmountOfIndexes();
	};
}

#endif