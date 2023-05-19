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
	}

	ShaderProgram::~ShaderProgram()
	{

	}

	unsigned int ShaderProgram::getShaderProgram()
	{
		return _shaderProgram;
	}

	void ShaderProgram::generateShaderProgram()
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

		glDeleteShader(vertexShader);

		glDeleteShader(fragmentShader);

		_shaderProgram = shaderProgram;
#pragma endregion
	}
}