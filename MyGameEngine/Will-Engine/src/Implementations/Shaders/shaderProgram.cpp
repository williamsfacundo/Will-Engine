#include "Shaders/shaderProgram.h"

#include <iostream>
#include <fstream>
#include <sstream>

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

	string ShaderProgram::getShaderSourceCode(const char* shaderSourceCodePath)
	{
		string shaderCode;

		ifstream shaderFile;

		shaderFile.exceptions(ifstream::failbit | ifstream::badbit);

		try
		{
			//open files
			shaderFile.open(shaderSourceCodePath);

			stringstream shaderStream;

			//read file's buffer contents into streams
			shaderStream << shaderFile.rdbuf();

			//close file handlers
			shaderFile.close();

			//convert stream into string
			shaderCode = shaderStream.str();
		}
		catch (ifstream::failure e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
		}

		return shaderCode;
	}

	unsigned int ShaderProgram::compileShader(const char* shaderSourceCode, bool isVertexShader)
	{
		unsigned int shaderId;

		int  success;

		char infoLog[512];

		if (isVertexShader)
		{
			shaderId = glCreateShader(GL_VERTEX_SHADER);
		}
		else
		{
			shaderId = glCreateShader(GL_FRAGMENT_SHADER);
		}

		glShaderSource(shaderId, 1, &shaderSourceCode, NULL);

		glCompileShader(shaderId);

		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shaderId, 512, NULL, infoLog);

			cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
		}

		return shaderId;
	}

	unsigned int ShaderProgram::linkShaders(unsigned int vertexShaderId, unsigned int fragmentShaderId)
	{
		int  success;

		char infoLog[512];

		unsigned int shaderProgramId = glCreateProgram();

		glAttachShader(shaderProgramId, vertexShaderId);

		glAttachShader(shaderProgramId, fragmentShaderId);

		glLinkProgram(shaderProgramId);

		glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(shaderProgramId, 512, NULL, infoLog);

			cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n" << infoLog << endl;
		}

		glDeleteShader(vertexShaderId);

		glDeleteShader(fragmentShaderId);

		return shaderProgramId;
	}

	void ShaderProgram::generateShaderProgramFromFiles(const char* vertexPath, const char* fragmentPath)
	{
		//Get the shaders source code from files
		string vertexShaderString = getShaderSourceCode(vertexPath);

		string fragmentShaderString = getShaderSourceCode(fragmentPath);
			
		const char* vertexShaderCode = vertexShaderString.c_str();

		const char* fragmentShaderCode = fragmentShaderString.c_str();

		//Generate shaders

		unsigned int vertexShaderId = compileShader(vertexShaderCode, true);		

		unsigned int fragmentShaderId = compileShader(fragmentShaderCode, false);		

		//Link the shaders to create program

		unsigned int shaderProgramId = linkShaders(vertexShaderId, fragmentShaderId);

		_shaderProgram = shaderProgramId;
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
		double timeValue = glfwGetTime();
		
		double greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		
		glUseProgram(_shaderProgram);
		
		glUniform4f(_vertexColorLocation, 0.0f, static_cast<GLfloat>(greenValue), 0.0f, 1.0f);
		
		glUseProgram(0);
	}

	void ShaderProgram::useShaderProgram()
	{
		glUseProgram(_shaderProgram);
	}
}