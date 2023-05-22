#ifndef INPUT_H
#define INPUT_H

#include "Core/window.h"

namespace WillEngine
{
	class Input
	{
	private:

	public:
		Input();
		~Input();

		void processInput(Window* window);
	};
}

#endif