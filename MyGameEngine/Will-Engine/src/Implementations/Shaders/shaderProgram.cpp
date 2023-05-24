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
			"}\n";

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
			"}\n";

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

	void ShaderProgram::generateShaderProgramFromFiles(const char* vertexPath, const char* fragmentPath)
	{
		//Get the shaders source code from files
		string vertexShaderString = getShaderSourceCode(vertexPath);

		string fragmentShaderString = getShaderSourceCode(fragmentPath);
			
		const char* vertexShaderCode = vertexShaderString.c_str();

		const char* fragmentShaderCode = fragmentShaderString.c_str();

		//Generate shaders

		unsigned int vertexShader = compileShader(vertexShaderCode, true);		

		unsigned int fragmentShader = compileShader(fragmentShaderCode, false);		

		//Link the shaders to create program

		_shaderProgram = glCreateProgram();

		glAttachShader(_shaderProgram, vertexShader);

		glAttachShader(_shaderProgram, fragmentShader);

		glLinkProgram(_shaderProgram);

		/*glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(_shaderProgram, 512, NULL, infoLog);

			cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n" << infoLog << endl;
		}*/

		glDeleteShader(vertexShader);

		glDeleteShader(fragmentShader);
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

		if(isVertexShader)
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