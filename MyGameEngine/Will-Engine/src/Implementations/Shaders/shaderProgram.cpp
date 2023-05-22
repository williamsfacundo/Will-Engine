#include "Shaders/shaderProgram.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>

using namespace std;

namespace WillEngine
{
	ShaderProgram::ShaderProgram()
	{
		_shaderProgram = 0;
		_vertexColorLocation = -1;
	}

	ShaderProgram::~ShaderProgram()
	{
		
	}	

	void ShaderProgram::generateShaderProgram()
	{
#pragma region VERTEX_SHADER
		const char* vertexShaderSource =
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec3 aColor;\n"
			"out vec3 ourColor;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos, 1.0);\n"
			"	ourColor = aColor;"
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
			"in vec3 ourColor;\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(ourColor, 1.0);\n"
			"}\0";

		unsigned int fragmentShader;

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

		glCompileShader(fragmentShader);		

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);

			cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
		}
#pragma endregion

#pragma region SHADER_PROGRM
		_shaderProgram = glCreateProgram();

		glAttachShader(_shaderProgram, vertexShader);

		glAttachShader(_shaderProgram, fragmentShader);

		glLinkProgram(_shaderProgram);

		glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(_shaderProgram, 512, NULL, infoLog);

			cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n" << infoLog << endl;
		}

		glDeleteShader(vertexShader);

		glDeleteShader(fragmentShader);		
#pragma endregion
	}

	void ShaderProgram::getColorUniform()
	{
		_vertexColorLocation = glGetUniformLocation(_shaderProgram, "ourColor");

		if(_vertexColorLocation == -1)
		{
			cout << "Could not find the location!\n" << endl;
		}
	}

	void ShaderProgram::updateColorUniform()
	{
		float timeValue = glfwGetTime();
		
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		
		glUseProgram(_shaderProgram);
		
		glUniform4f(_vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
		
		glUseProgram(0);
	}

	void ShaderProgram::useShaderProgram()
	{
		glUseProgram(_shaderProgram);
	}
}

/*void Engine::setVertexShader()
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
	}*/

	/*void Engine::setFragmentShader()
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
	}*/