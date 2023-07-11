#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>

#include "Shaders/shader.h"
#include "Objects/transform.h"

using namespace glm;

namespace WillEngine
{	 
	class Camera
	{
	private:
		Transform* _cameraTransform;

		mat4 _viewMatrix;

		int _viewMatrixLocation;	

		void updateViewMatrixUniformData();

	public:
		Camera(Shader* shader);
		~Camera();				

		void updateViewMatrix();

		Transform* getCameraTransform();
	};
}

#endif