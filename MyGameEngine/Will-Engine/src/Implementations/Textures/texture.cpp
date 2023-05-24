#include "Textures/texture.h"

namespace WillEngine
{
	Texture::Texture(unsigned int textureId, int width, int height, int nrChannels)
	{
		_textureId = textureId;

		_width = width;

		_height = height;

		_nrChannels = nrChannels;
	}

	Texture::~Texture()
	{

	}	

	unsigned int Texture::getTextureId()
	{
		return _textureId;
	}

	int Texture::getWidth()
	{
		return _width;
	}

	int Texture::getHeight()
	{
		return _height;
	}

	int Texture::getNRChannels()
	{
		return _nrChannels;
	}
}