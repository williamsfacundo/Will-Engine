#include "Core/window.h"

namespace WillEngine
{
	Window::Window()
	{
		_gLFWwindow = nullptr;

		_windowWidth = DefaultWindowWidth;
		_windowHeight = DefaultWindowHeight;
	}

	Window::Window(int windowWidth, int windowHeight)
	{
		_gLFWwindow = nullptr;

		_windowWidth = windowWidth;
		_windowHeight = windowHeight;
	}

	Window::~Window()
	{
		if (_gLFWwindow != nullptr)
		{
			glfwDestroyWindow(_gLFWwindow);
		}
	}

	GLFWwindow* Window::getGLFWwindow()
	{
		return _gLFWwindow;
	}

	bool Window::initWindow()
	{
		_gLFWwindow = glfwCreateWindow(_windowWidth, _windowHeight, WindowInitialName, NULL, NULL);

		if (_gLFWwindow == nullptr)
		{
			return false;
		}

		return true;
	}

	void Window::createValidOpenglContext()
	{
		if(_gLFWwindow != nullptr)
		{
			glfwMakeContextCurrent(_gLFWwindow);
		}
	}
}