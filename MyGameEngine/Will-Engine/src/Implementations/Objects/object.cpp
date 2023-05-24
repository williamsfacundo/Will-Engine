#include "Objects/object.h"

#include <glew.h>
#include <glfw3.h>

namespace WillEngine
{
	void Object::setVertexArray(unsigned int vertexArray)
	{
		_vertexArray = vertexArray;
	}

	Object::Object()
	{
		_shader = nullptr;

		_vertexArray = 0;
	}

	Object::~Object()
	{

	}

	Shader* Object::getShader()
	{
		return _shader;
	}	

	void Object::createObject(Shader* objectShader)
	{
		_shader = objectShader;

		setData();
	}	

	void Object::selectObject()
	{
		glBindVertexArray(_vertexArray);
	}
}