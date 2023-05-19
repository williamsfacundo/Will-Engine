#include "Core/Engine.h"

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

	void Engine::setVertexData()
	{
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
		};

		unsigned int VBO;

		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		
		glEnableVertexAttribArray(0);
	}

	void Engine::setVertexShader()
	{
		const char* vertexShaderSource = 
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

		unsigned int vertexShader;
		
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

		glCompileShader(vertexShader);

		int  success;

		char infoLog[512];

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

			cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
		}
	}

	void Engine::setFragmentShader()
	{
		const char* fragmentShaderSource =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\0";

		unsigned int fragmentShader;

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

		glCompileShader(fragmentShader);

		int  success;

		char infoLog[512];

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);

			cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
		}
	}

	void Engine::setShaderProgram()
	{
#pragma region VERTEX_SHADER
		const char* vertexShaderSource =
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

		unsigned int vertexShader;

		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

		glCompileShader(vertexShader);

		int  success;

		char infoLog[512];

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

			cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
		}
#pragma endregion

#pragma region FRAGMENT_SHADER
		const char* fragmentShaderSource =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\0";

		unsigned int fragmentShader;

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

		glCompileShader(fragmentShader);

		//int  success;

		//char infoLog[512];

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);

			cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
		}
#pragma endregion

#pragma region SHADER_PROGRM
		unsigned int shaderProgram;

		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);

		glAttachShader(shaderProgram, fragmentShader);

		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		
		if (!success) 
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

			cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n" << infoLog << endl;
		}

		glUseProgram(shaderProgram);

		glDeleteShader(vertexShader);

		glDeleteShader(fragmentShader);
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

	void Engine::engineDeinitialization()
	{
		destroyObjects();

		closeGLFW();
	}

	void Engine::destroyObjects()
	{
		if (_window != nullptr) { delete _window; }
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