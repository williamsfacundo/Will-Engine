#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm.hpp>

#include "Shaders/shader.h"

using namespace glm;

namespace WillEngine
{
	class Transform
	{
	private:
		const vec3 WorldOrigin = vec3(0.0f, 0.0f, 0.0f);
		const vec3 WorldRight = vec3(1.0f, 0.0f, 0.0f);
		const vec3 WorldUp = vec3(0.0f, 0.1f, 0.0f);
		
		mat4 _xRotationMatrix;
		mat4 _yRotationMatrix;
		mat4 _zRotationMatrix;

		mat4 _translationMatrix;
		mat4 _rotationMatrix;
		mat4 _scalingMatrix;

		mat4 _modelMatrix;

		vec3 _positionVector;
		vec3 _rotationVector;
		vec3 _scaleVector;

		int _transformLocation;

		void updateModelMatrixUniformData();

	public:
		Transform(Shader* shader);
		~Transform();

		void setDefaultTransform();

		void updateModelMatrix();
	};
}

#endif