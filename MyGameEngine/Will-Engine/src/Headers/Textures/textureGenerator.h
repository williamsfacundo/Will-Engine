#ifndef TEXTURE_GENERATOR_H
#define TEXTURE_GENERATOR_H

#include "Textures/texture.h"

namespace WillEngine
{
	class TextureGenerator
	{
	private:
		static int TextureIndex;

	public:		

		static Texture* generateTexture(const char* texturePathFile);
	};
}

#endif