#include "Core/engine.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "Core/window.h"
#include "Core/callback_functions.h"

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

	void Engine::setShaderProgram()
	{
		_shaderProgram = new ShaderProgram();

		_shaderProgram->generateShaderProgram();
	}

	void Engine::setVertexData()
	{
#pragma region INITIALIZATION
		float vertices[] = 
		{
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
		};

		unsigned int indices[] = 
		{  
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};

		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;

		glGenBuffers(1, &VBO);

		glGenVertexArrays(1, &VAO);

		glGenBuffers(1, &EBO);
#pragma endregion

#pragma region CONFIGURATION
		glBindVertexArray(VAO); //Saves all the configurations of the object

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		
		glEnableVertexAttribArray(0);		

		glBindVertexArray(0); //This must be unbined first not to save unbined buffers 

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		_vertexArray = VAO;
#pragma endregion
	}	

	void Engine::engineLoop()
	{
		while (!glfwWindowShouldClose(_window->getGLFWwindow()))
		{
			//Input
			processInput();

			//Rendering
			RenderingCommands();			
			
			drawTriangles();

			glfwSwapBuffers(_window->getGLFWwindow());

			glfwPollEvents();
		}
	}

	void Engine::processInput()
	{
		if (glfwGetKey(_window->getGLFWwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(_window->getGLFWwindow(), true);
		}
	}	

	void Engine::RenderingCommands()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Engine::drawTriangles()
	{
		_shaderProgram->useShaderProgram();
		
		glBindVertexArray(_vertexArray);
		
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);	
	}

	void Engine::engineDeinitialization()
	{
		destroyObjects();

		closeGLFW();
	}

	void Engine::destroyObjects()
	{
		if (_window != nullptr) { delete _window; }

		if (_shaderProgram != nullptr) { delete _shaderProgram; }
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
		
		_shaderProgram = nullptr;

		_shaderProgram = 0;
		
		_vertexArray = 0;

		_isGLFWInited = false;
	}

	Engine::~Engine()
	{

	}	

	void Engine::runEngine()
	{
		if (engineInitialization() == SUCCESSFUL_INITIALIZATION)
		{
			setShaderProgram();		

			setVertexData();			

			engineLoop();
		}

		engineDeinitialization();
	}
}