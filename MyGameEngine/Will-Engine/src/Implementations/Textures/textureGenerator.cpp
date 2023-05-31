#define STB_IMAGE_IMPLEMENTATION

#include "Textures/textureGenerator.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "Textures/stb_image.h"

using namespace std;

namespace WillEngine
{
	int TextureGenerator::TextureIndex = 0;

	Texture* TextureGenerator::generateTexture(const char* texturePathFile)
	{
		unsigned int textureId;

		stbi_set_flip_vertically_on_load(true);

		glGenTextures(1, &textureId);

		glActiveTexture(GL_TEXTURE0);

		glBindTexture(GL_TEXTURE_2D, textureId);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		

		// load and generate the texture
		int width, height, nrChannels;

		unsigned char* data = stbi_load(texturePathFile, &width, &height, &nrChannels, 0);
		
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			cout << "Failed to load texture" << endl;
		}
		
		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(data);

		TextureIndex += 1;

		return new Texture(textureId, width, height, nrChannels);
	}
}