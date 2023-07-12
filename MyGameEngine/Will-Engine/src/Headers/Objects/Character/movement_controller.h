#ifndef MOVEMENT_CONTROLLER_H
#define MOVEMENT_CONTROLLER_H

#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"
#include "Enums/movement_enum.h"
#include "Objects/objectTransform.h"
#include "Objects/transform.h"

namespace WillEngine
{
	class MovementController
	{
	private:
		const float DefaultMoveSpeed = 2.0f;
		
		const int DefaultMoveForwardKey = GLFW_KEY_W;
		const int DefaultMoveBackwardKey = GLFW_KEY_S;
		const int DefaultMoveRightKey = GLFW_KEY_D;
		const int DefaultMoveLeftKey = GLFW_KEY_A;

		Window* _window;
		ObjectTransform* _characterTransform;
		Transform* _cameraTransform;

		MovementEnum _horizontalKeyboardInput;
		MovementEnum _verticalKeyboardInput;

		float _moveSpeed;
		float _initialYPos;

		int _moveForwardKey;
		int _moveBackwardKey;
		int _moveRightKey;
		int _moveLeftKey;

		bool _moveInputDetected;
		bool _canFly;

	public:
		MovementController(Window* window, ObjectTransform* characterTransform, Transform* cameraTransform);
		MovementController(Window* window, ObjectTransform* characterTransform, Transform* cameraTransform, float moveSpeed);
		~MovementController();

		void setMoveSpeed(float moveSpeed);
		
		void setMoveForwardKey(int newKey);
		void setMoveBackwardKey(int newKey);
		void setMoveRightKey(int newKey);
		void setMoveLeftKey(int newKey);

		void setInputKeysToDefault();

		float getMoveSpeed();

		bool getMoveInputDetected();
		
		void input();

		void update();
	};
}

#endif