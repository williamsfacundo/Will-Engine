#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>

#include "Shaders/shader.h"

using namespace glm;

namespace WillEngine
{
	class Camera
	{
	private:
		vec3 _position;

		vec3 _front;
		vec3 _up;
		vec3 _right;

		mat4 _viewMatrix;

		int _viewMatrixLocation;

	public:
		Camera(Shader* shader);
		~Camera();

		void updateViewMatrixUniformData();
	};
}

#endif