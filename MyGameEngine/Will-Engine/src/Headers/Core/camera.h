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
		mat4 _viewMatrix;

		unsigned int _viewMatrixLocation;

	public:
		Camera(Shader* shader);
		~Camera();

		void updateViewMatrixUniformData();
	};
}

#endif