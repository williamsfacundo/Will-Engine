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

		void setData();

	public:
		Object();
		~Object();

		Shader* getShader();

		int getAmountOfIndexes();

		void createObject(Shader* objectShader);		

		void selectObject();
	};
}

#endif