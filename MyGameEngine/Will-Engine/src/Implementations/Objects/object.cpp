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

	void Object::setObjectTransform(ObjectTransform* objectTransform)
	{
		_objectTransform = objectTransform;
	}

	Object::Object(Shader* objectShader)
	{
		/*_shader = nullptr;

		_texture = nullptr;

		_objectTransform = nullptr;

		_vertexArray = 0;*/

		_texture = nullptr;

		_vertexArray = 0;

		_shader = objectShader;

		_objectTransform = new ObjectTransform(_shader);	
	}

	Object::~Object()
	{
		if (_objectTransform != nullptr) { delete _objectTransform; };
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

	ObjectTransform* Object::getObjectTransform()
	{
		return _objectTransform;
	}

	void Object::createObject(Shader* objectShader)
	{
		//_shader = objectShader;	

		//_objectTransform = new ObjectTransform(_shader);

		setData();
	}	

	void Object::selectObject()
	{
		glBindVertexArray(_vertexArray);
	}
}