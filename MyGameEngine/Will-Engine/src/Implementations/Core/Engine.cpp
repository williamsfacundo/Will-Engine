#include "Core/engine.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"
#include "Core/renderer.h"
#include "Core/input.h"
#include "Shaders/shader.h"
#include "Objects/cube.h"
#include "Core/callback_functions.h"
#include "Textures/texture.h"
#include "Textures/textureGenerator.h"
#include "Core/delta_time.h"

using namespace std;

namespace WillEngine
{
	int Engine::engineInitialization()
	{
		if (gLFWInitialization() == INITIALIZATION_FAILED)
		{
			return INITIALIZATION_FAILED;
		}

		gLFWHintsInitialization();

		if (windowInitialization() == INITIALIZATION_FAILED)
		{
			return INITIALIZATION_FAILED;
		}

		if(gLEWInitialization() == INITIALIZATION_FAILED)
		{
			return INITIALIZATION_FAILED;
		}

		gLFWCallbackFunstionsRegister();

		gLFWFunctionsSettings();

		enableOpenglFuntionalities();

		return SUCCESSFUL_INITIALIZATION;
	}

	int Engine::gLFWInitialization()
	{
		if (!glfwInit())
		{
			cout << "GLFW library failed to initialized!\n" << endl;

			return INITIALIZATION_FAILED;
		}

		_isGLFWInited = true;

		return SUCCESSFUL_INITIALIZATION;
	}

	void Engine::gLFWHintsInitialization()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //This set the Opengl "Right part" Version: this is v3.x 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //This set the Opengl "Left part" Version: this is v3.3
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Encourages the use of modern OpenGL
	}

	int Engine::windowInitialization()
	{
		_window = new Window();	

		if (!_window->initWindow())
		{
			cout << "Failed to create GLFW window" << std::endl;

			return INITIALIZATION_FAILED;
		}

		_window->createValidOpenglContext();

		return SUCCESSFUL_INITIALIZATION;
	}

	int Engine::gLEWInitialization() 
	{
		if (GLEW_OK != glewInit())
		{
			return INITIALIZATION_FAILED;
		}

		return SUCCESSFUL_INITIALIZATION;
	}

	void Engine::gLFWCallbackFunstionsRegister() 
	{
		glfwSetFramebufferSizeCallback(_window->getGLFWwindow(), framebuffer_size_callback);				
	}	

	void Engine::gLFWFunctionsSettings()
	{
		glfwSetInputMode(_window->getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void Engine::enableOpenglFuntionalities()
	{
		glEnable(GL_DEPTH_TEST);
	}

	void Engine::setShaders()
	{
		_shader = new Shader("res/Shaders/vertex-shader-source.txt",
			"res/Shaders/fragment-shader-source.txt");
	}

	void Engine::setObjects()
	{
		_object = new Cube();

		_object->createObject(_shader);		
	
		_object->setTexture(_texture);
	}	

	void Engine::setRenderer()
	{
		_renderer = new Renderer(_shader);
	}

	void Engine::setInput()
	{
		_input = new Input();
	}

	void Engine::setTexture()
	{
		_texture = TextureGenerator::generateTexture("res/Textures/image.png");
	}

	void Engine::setCamera()
	{
		_camera = new Camera(_shader);
	}

	void Engine::engineLoop()
	{
		while (!glfwWindowShouldClose(_window->getGLFWwindow()))
		{
			//Input
			_input->processInput(_window);
			_input->processInput(_window, _camera);

			//Update
			DeltaTime::updateDeltaTime();

			//Rendering
			_renderer->renderingCommands();
			
			_renderer->drawObject(_object, _camera);

			//GLFW commands
			glfwSwapBuffers(_window->getGLFWwindow());

			glfwPollEvents();
		}
	}	

	void Engine::engineDeinitialization()
	{
		destroyObjects();

		closeGLFW();
	}

	void Engine::destroyObjects()
	{
		if (_window != nullptr) { delete _window; }

		if (_shader != nullptr) { delete _shader; }

		if (_object != nullptr) { delete _object; }

		if (_renderer != nullptr) { delete _renderer; }

		if (_input != nullptr) { delete _input; }

		if (_texture != nullptr) { delete _texture; }

		if (_camera != nullptr) { delete _camera; }
	}

	void Engine::closeGLFW()
	{
		if (_isGLFWInited)
		{
			glfwTerminate();
		}
	}

	Engine::Engine()
	{
		_window = nullptr;		
		
		_shader = nullptr;

		_object = nullptr;

		_renderer = nullptr;

		_input = nullptr;	

		_texture = nullptr;

		_camera = nullptr;

		_isGLFWInited = false;
	}

	Engine::~Engine()
	{
		engineDeinitialization();
	}	

	void Engine::runEngine()
	{
		if (engineInitialization() == SUCCESSFUL_INITIALIZATION)
		{
			setShaders();		

			setTexture();

			setObjects();

			setRenderer();

			setInput();

			setCamera();

			engineLoop();
		}
	}
}