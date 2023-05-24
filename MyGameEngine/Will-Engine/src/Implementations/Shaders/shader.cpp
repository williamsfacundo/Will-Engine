#include "Shaders/shader.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "Shaders/shaderCreator.h"

using namespace std;

namespace WillEngine
{
	Shader::Shader(const char* vertexShaderSourcePath, const char* fragmentShaderSourcePath)
	{
		_shaderId = ShaderCreator::generateShaderProgramFromFiles(vertexShaderSourcePath, fragmentShaderSourcePath);

		_vertexColorLocation = -1;
	}

	Shader::~Shader()
	{

	}

	void Shader::getColorUniform()
	{
		_vertexColorLocation = glGetUniformLocation(_shaderId, "ourColor");

		if (_vertexColorLocation == -1)
		{
			cout << "Could not find the location!\n" << endl;
		}
	}

	void Shader::updateColorUniform()
	{
		double timeValue = glfwGetTime();

		double greenValue = (sin(timeValue) / 2.0f) + 0.5f;

		glUseProgram(_shaderId);

		glUniform4f(_vertexColorLocation, 0.0f, static_cast<GLfloat>(greenValue), 0.0f, 1.0f);

		glUseProgram(0);
	}

	void Shader::useShaderProgram()
	{
		glUseProgram(_shaderId);
	}
}