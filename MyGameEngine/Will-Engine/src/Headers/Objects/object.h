#ifndef OBJECT_H
#define OBJECT_H

#include "Shaders/shader.h"
#include "Textures/texture.h"
#include "objectTransform.h"

namespace WillEngine
{
	class Object
	{
	private:
		Shader* _shader;
		Texture* _texture;
		ObjectTransform* _objectTransform;

		unsigned int _vertexArray;

	protected:
		virtual void setData() = 0;

		void setVertexArray(unsigned int vertexArray);

		void setObjectTransform(ObjectTransform* objectTransform);
	public:
		Object(Shader* objectShader);
		~Object();

		void setTexture(Texture* texture);		

		Shader* getShader();

		Texture* getTexture();

		ObjectTransform* getObjectTransform();

		virtual int getAmountOfIndexes() = 0;

		void createObject(Shader* objectShader);		

		void selectObject();
	};
}

#endif