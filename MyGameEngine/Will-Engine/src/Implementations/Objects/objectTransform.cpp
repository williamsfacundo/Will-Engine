#include "Objects/objectTransform.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Objects/transform.h"
#include "Shaders/shader.h"

using namespace glm;
using namespace std;

namespace WillEngine
{
	void ObjectTransform::updateModelMatrixUniformData()
	{
		glUniformMatrix4fv(_transformLocation, 1, GL_FALSE, value_ptr(_modelMatrix));
	}

	ObjectTransform::ObjectTransform(Shader* shader)
	{
		setDefaultTransform();

		_transformLocation = shader->getUniformLocation("modelMatrix");

		if (_transformLocation == -1)
		{
			cout << "Could not find the model matrix uniform location!\n" << endl;
		}
	}

	ObjectTransform::~ObjectTransform()
	{

	}

	void ObjectTransform::setDefaultObjectTransform()
	{
		setDefaultTransform();

		_xRotationMatrix = mat4();

		_yRotationMatrix = mat4();

		_zRotationMatrix = mat4();

		_translationMatrix = mat4();

		_rotationMatrix = mat4();

		_scalingMatrix = mat4();				

		_modelMatrix = mat4(1.0f);
	}

	void ObjectTransform::updateModelMatrix()
	{
		_translationMatrix = translate(mat4(1.0f), getLocalPosition());

		_scalingMatrix = scale(mat4(1.0f), getLocalScale());

		_xRotationMatrix = rotate(mat4(1.0f), radians(getLocalRotation().x), vec3(1.0f, 0.0f, 0.0f));

		_yRotationMatrix = rotate(mat4(1.0f), radians(getLocalRotation().y), vec3(0.0f, 1.0f, 0.0f));

		_zRotationMatrix = rotate(mat4(1.0f), radians(getLocalRotation().z), vec3(0.0f, 0.0f, 1.0f));

		_rotationMatrix = _xRotationMatrix * _yRotationMatrix * _zRotationMatrix;

		_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;

		updateModelMatrixUniformData();
	}
}