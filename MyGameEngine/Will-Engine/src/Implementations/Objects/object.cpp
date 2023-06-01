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

	void Object::setTransform(Transform* transform)
	{
		_transform = transform;
	}

	Object::Object()
	{
		_shader = nullptr;

		_texture = nullptr;

		_transform = nullptr;

		_vertexArray = 0;
	}

	Object::~Object()
	{
		if (_transform != nullptr) { delete _transform; };
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

	Transform* Object::getTransform()
	{
		return _transform;
	}

	void Object::createObject(Shader* objectShader)
	{
		_shader = objectShader;	

		_transform = new Transform(_shader);

		setData();
	}	

	void Object::selectObject()
	{
		glBindVertexArray(_vertexArray);
	}
}