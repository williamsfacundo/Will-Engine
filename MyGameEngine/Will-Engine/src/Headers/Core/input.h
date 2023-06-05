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
		void processInput(Window* window, Camera* camera);

		static void mousePosition(Window* window, double& xPos, double& yPos);
	};
}

#endif