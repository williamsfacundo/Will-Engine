#include "Objects/cube.h"

#include <glew.h>
#include <glfw3.h>

namespace WillEngine
{
	void Cube::setData()
	{
#pragma region INITIALIZATION
		//        POSITION             COLOR       TEXT COORDS
		float vertices[] =
		{
			//Front face
			-0.5f, -0.5f, 0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, // Bottom-left
			 0.5f, -0.5f, 0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // Bottom-right
			 0.5f,  0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f, // Top-right
			-0.5f,  0.5f, 0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, // Top-left

			//Back Face
			-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f, // Bottom-left
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f, // Bottom-right
			 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f, // Top-right
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, // Top-left

			//Top Face
			-0.5f, 0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f, // Bottom-left
			 0.5f, 0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, // Bottom-right
			 0.5f, 0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f, // Top-right
			-0.5f, 0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f, // Top-left

			//Bottom Face
			-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, // Bottom-left
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // Bottom-right
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f, // Top-right
			-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, // Top-left

			//Right Face
			0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, // Bottom-left
			0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // Bottom-right
			0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f, // Top-right
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, // Top-left

			//Left Face
			-0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f, // Bottom-left
			-0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f, // Bottom-right
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,  // Top-right
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f // Top-left
		};

		unsigned int indices[] = 
		{
			// Front face
			0, 1, 2,
			2, 3, 0,

			// Back face
			4, 5, 6,
			6, 7, 4,

			// Top face
			8, 9, 10,
			10, 11, 8,

			// Bottom face
			12, 13, 14,
			14, 15, 12,

			// Right face
			16, 17, 18,
			18, 19, 16,

			// Left face
			20, 21, 22,
			22, 23, 20
		};

		unsigned int VBO;
		unsigned int EBO;
		unsigned int VAO;

		glGenBuffers(1, &VBO);

		glGenVertexArrays(1, &VAO);

		glGenBuffers(1, &EBO);
#pragma endregion

#pragma region CONFIGURATION
		glBindVertexArray(VAO); //From this point will saves all the configurations of the object		

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//Position Attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));

		glEnableVertexAttribArray(1);

		//Texture coordinate attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

		glEnableVertexAttribArray(2);

		glBindVertexArray(0); //This must be unbined first not to save unbined buffers 

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
#pragma endregion

		setVertexArray(VAO);
	}

	Cube::Cube() : Object()
	{

	}

	Cube::~Cube()
	{

	}

	int Cube::getAmountOfIndexes()
	{
		return 36;
	}
}