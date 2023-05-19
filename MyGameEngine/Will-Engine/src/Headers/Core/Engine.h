#ifndef ENGINE_H
#define ENGINE_H

#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"

namespace WillEngine
{
#define SUCCESSFUL_INITIALIZATION 0
#define INITIALIZATION_FAILED -1	

	class Engine
	{
	private:
#pragma region VARIABLES
		Window* _window;

		bool _isGLFWInited;
#pragma endregion

#pragma region FUNCTIONS

#pragma region INITIALIZATION
		int engineInitialization();

		int gLFWInitialization();

		void gLFWHintsInitialization();

		int windowInitialization();

		int gLEWInitialization();

		void gLFWCallbackFunstionsRegister();

		void setVertexData();

		void setVertexShader();

		void setFragmentShader();
#pragma endregion

#pragma region UPDATE
		void engineLoop();

		void processInput();

		void RenderingCommands();
#pragma endregion

#pragma region DEINITIALIZATION
		void engineDeinitialization();

		void destroyObjects();

		void closeGLFW();
#pragma endregion

#pragma endregion

	public:	
		Engine();
		~Engine();

		void runEngine();
	};
}

#endif