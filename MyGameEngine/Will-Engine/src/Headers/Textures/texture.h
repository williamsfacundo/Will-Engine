#ifndef TEXTURES_H
#define TEXTURES_H

namespace WillEngine
{
	class Texture
	{
	private:
		unsigned int _textureId;

		int _width;
		int _height; 
		int _nrChannels;		

	public:
		Texture(unsigned int textureId, int width, int height, int nrChannels);

		~Texture();

		unsigned int getTextureId();

		int getWidth();
		int getHeight();
		int getNRChannels();
	};
}

#endif