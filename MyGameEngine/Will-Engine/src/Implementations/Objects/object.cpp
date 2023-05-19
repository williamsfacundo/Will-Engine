#include "Objects/object.h"

#include <glew.h>
#include <glfw3.h>

namespace WillEngine
{
	Object::Object()
	{
		_vertexArray = 0;
	}

	Object::~Object()
	{

	}

	void Object::createObject()
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
		unsigned int EBO;

		glGenBuffers(1, &VBO);

		glGenVertexArrays(1, &_vertexArray);

		glGenBuffers(1, &EBO);
#pragma endregion

#pragma region CONFIGURATION
		selectObject(); //From this point will saves all the configurations of the object

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		glBindVertexArray(0); //This must be unbined first not to save unbined buffers 

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);		
#pragma endregion
	}

	void Object::selectObject()
	{
		glBindVertexArray(_vertexArray);
	}
}