#include "Objects/object.h"

#include <glew.h>
#include <glfw3.h>

#include "Shaders/shader.h"
#include "Textures/texture.h"

namespace WillEngine
{
	void Object::setVertexArray(unsigned int vertexArray)
	{
		_vertexArray = vertexArray;
	}

	Object::Object()
	{
		_shader = nullptr;

		_texture = nullptr;

		_vertexArray = 0;
	}

	Object::~Object()
	{

	}

	void Object::setTexture(Texture* texture)
	{
		_texture = texture;
	}

	Shader* Object::getShader()
	{
		return _shader;
	}	

	Texture* Object::getTexture()
	{
		return _texture;
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