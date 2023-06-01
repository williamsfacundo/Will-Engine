#ifndef OBJECT_H
#define OBJECT_H

#include "Shaders/shader.h"
#include "Textures/texture.h"
#include "transform.h"

namespace WillEngine
{
	class Object
	{
	private:
		Shader* _shader;
		Texture* _texture;
		Transform* _transform;

		unsigned int _vertexArray;

	protected:
		virtual void setData() = 0;

		void setVertexArray(unsigned int vertexArray);

		void setTransform(Transform* transform);
	public:
		Object();
		~Object();

		void setTexture(Texture* texture);		

		Shader* getShader();

		Texture* getTexture();

		Transform* getTransform();

		virtual int getAmountOfIndexes() = 0;

		void createObject(Shader* objectShader);		

		void selectObject();
	};
}

#endif