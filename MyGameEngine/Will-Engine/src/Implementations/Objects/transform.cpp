#include "Objects/transform.h"

#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Shaders/shader.h"

using namespace glm;
using namespace std;

namespace WillEngine
{
	void Transform::updateModelMatrixUniformData()
	{
		glUniformMatrix4fv(_transformLocation, 1, GL_FALSE, value_ptr(_modelMatrix));	
	}

	Transform::Transform(Shader* shader)
	{
		setDefaultTransform();		

		_transformLocation = shader->getUniformLocation("modelMatrix");

		if(_transformLocation == -1)
		{
			cout << "Could not find the model matrix uniform location!\n" << endl;
		}	
	}

	Transform::~Transform()
	{

	}

	void Transform::setDefaultTransform()
	{
		_xRotationMatrix = mat4();

		_yRotationMatrix = mat4();

		_zRotationMatrix = mat4();

		_translationMatrix = mat4();

		_rotationMatrix = mat4();

		_scalingMatrix = mat4();

		_modelMatrix = mat4();

		_positionVector = vec3(0.0f, 0.0f, -5.0f);

		_rotationVector = vec3(0.0f, 0.0f, 0.0f);
		
		_scaleVector = vec3(1.0f, 1.0f, 1.0f);

		_modelMatrix = mat4(1.0f);
	}

	void Transform::updateModelMatrix()
	{
		_translationMatrix = translate(mat4(1.0f), _positionVector);

		_scalingMatrix = scale(mat4(1.0f), _scaleVector);

		_xRotationMatrix = rotate(mat4(1.0f), radians(_rotationVector.x), vec3(1.0f, 0.0f, 0.0f));

		_yRotationMatrix = rotate(mat4(1.0f), radians(_rotationVector.y), vec3(0.0f, 1.0f, 0.0f));

		_zRotationMatrix = rotate(mat4(1.0f), radians(_rotationVector.z), vec3(0.0f, 0.0f, 1.0f));

		_rotationMatrix = _xRotationMatrix * _yRotationMatrix * _zRotationMatrix;

		_modelMatrix = _translationMatrix * _rotationMatrix * _scalingMatrix;		

		updateModelMatrixUniformData();
	}	
}