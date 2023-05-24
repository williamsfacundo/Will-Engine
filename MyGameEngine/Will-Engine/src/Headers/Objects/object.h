#ifndef OBJECT_H
#define OBJECT_H

#include "Shaders/shader.h"
#include "Textures/texture.h"

namespace WillEngine
{
	class Object
	{
	private:
		Shader* _shader;
		Texture* _texture;

		unsigned int _vertexArray;

	protected:
		virtual void setData() = 0;

		void setVertexArray(unsigned int vertexArray);
	public:
		Object();
		~Object();

		void setTexture(Texture* texture);

		Shader* getShader();

		Texture* getTexture();

		virtual int getAmountOfIndexes() = 0;

		void createObject(Shader* objectShader);		

		void selectObject();
	};
}

#endif