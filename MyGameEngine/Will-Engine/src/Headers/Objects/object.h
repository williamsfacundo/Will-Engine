#ifndef OBJECT_H
#define OBJECT_H

#include "Shaders/shader.h"

namespace WillEngine
{
	class Object
	{
	private:
		Shader* _shader;

		unsigned int _vertexArray;

	protected:
		virtual void setData() = 0;

		void setVertexArray(unsigned int vertexArray);
	public:
		Object();
		~Object();

		Shader* getShader();

		virtual int getAmountOfIndexes() = 0;

		void createObject(Shader* objectShader);		

		void selectObject();
	};
}

#endif