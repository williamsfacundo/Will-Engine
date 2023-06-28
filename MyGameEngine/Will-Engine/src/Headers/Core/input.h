#ifndef INPUT_H
#define INPUT_H

#include "Core/window.h"
#include "Core/camera.h"

namespace WillEngine
{
	class Input
	{
	public:
		Input();
		~Input();

		void processInput(Window* window);

		static bool isKeyPressed(Window* window, int key);

		static void mousePosition(Window* window, double& xPos, double& yPos);
	};
}

#endif