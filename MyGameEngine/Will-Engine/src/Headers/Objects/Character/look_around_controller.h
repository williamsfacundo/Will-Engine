#ifndef LOOK_AROUND_CONTROLLER_H
#define LOOK_AROUND_CONTROLLER_H

#include "Core/window.h"
#include "Objects/transform.h"

namespace WillEngine
{
	class LookAroundController
	{
	private:
		const float DefaultMouseSensitivity = 0.1f;

		Window* _window;
		Transform* _cameraTransform;

		float _mouseSensitivity;

		double _mouseXPos;
		double _mouseYPos;

		double _lastMouseXPos;
		double _lastMouseYPos;

		float _mouseXOffset;
		float _mouseYOffset;
		
		bool _firstMouse;

	public:
		LookAroundController(Window* window, Transform* cameraTransform);
		~LookAroundController();

		void setMouseSensitivity(float mouseSensitivity);

		float getMouseSensitivity();

		void update();
	};
}

#endif