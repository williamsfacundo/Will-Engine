#ifndef ENGINE_H
#define ENGINE_H

#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"
#include "Core/renderer.h"
#include "Core/input.h"
#include "Shaders/shader.h"
#include "Objects/object.h"

namespace WillEngine
{
#define SUCCESSFUL_INITIALIZATION 0
#define INITIALIZATION_FAILED -1	

	class Engine
	{
	private:
#pragma region VARIABLES
		Window* _window;
		Shader* _shader;
		Object* _object;	
		Renderer* _renderer;
		Input* _input;

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

		void setShaderProgram();

		void setObjects();

		void setRenderer();

		void setInput();
#pragma endregion

#pragma region UPDATE
		void engineLoop();		
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