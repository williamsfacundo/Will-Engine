#ifndef WINDOW_H
#define WINDOW_H

#include <glfw3.h>

namespace WillEngine
{	
	class Window
	{
	private:
		const int DefaultWindowWidth = 800;
		const int DefaultWindowHeight = 600;
		
		const char* WindowInitialName = "ENGINE";

		GLFWwindow* _gLFWwindow;

		int _windowWidth;
		int _windowHeight;

	public:
		Window();
		Window(int windowWidth, int windowHeight);
		~Window();

		bool initWindow();

		void createValidOpenglContext();
	};
}

#endif