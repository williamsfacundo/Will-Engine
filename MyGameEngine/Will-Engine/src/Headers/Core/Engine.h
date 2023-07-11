#ifndef ENGINE_H
#define ENGINE_H

#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"
#include "Core/renderer.h"
#include "Core/input.h"
#include "Shaders/shader.h"
#include "Objects/object.h"
#include "Textures/texture.h"
#include "Camera/camera.h"
#include "Objects/Character/character.h"

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
		Texture* _texture;
		Camera* _camera;
		Character* _character;

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

		void gLFWFunctionsSettings();

		void enableOpenglFuntionalities();

		void setShaders();

		void setObjects();

		void setRenderer();

		void setInput();

		void setTexture();

		void setCamera();

		void setCharacter();
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

	protected:
		Engine(); //Create a game class and make it inherit from this one

		//Create the objects for you game
		virtual void userInitialization() = 0;

		//Input goes here
		virtual void userInput() = 0;

		//Update positions and those stuf here
		virtual void userUpdate() = 0;

		//Call the draw function of objects here
		virtual void userDraw() = 0;

		//Delete the objects here
		virtual void userDeinitialization() = 0;

	public:	
		~Engine();

		void runEngine(); //Call this function one time to start the engine 
	};
}

#endif