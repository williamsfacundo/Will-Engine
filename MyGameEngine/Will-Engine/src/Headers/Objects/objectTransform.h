#ifndef OBJECT_TRANSFORM_H
#define OBJECT_TRANSFORM_H

#include <glm.hpp>

#include "transform.h"
#include "Shaders/shader.h"

using namespace glm;

namespace WillEngine
{
	class ObjectTransform : public Transform
	{
	private:
		mat4 _xRotationMatrix;
		mat4 _yRotationMatrix;
		mat4 _zRotationMatrix;

		mat4 _translationMatrix;
		mat4 _rotationMatrix;
		mat4 _scalingMatrix;

		mat4 _modelMatrix;

		int _transformLocation;

		void updateModelMatrixUniformData();

	public:
		ObjectTransform(Shader* shader);
		~ObjectTransform();

		void setDefaultTransform();

		void updateModelMatrix();
	};
}

#endif