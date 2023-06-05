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
		const float _cameraSpeed = 0.005f;
		
		vec3 _position;

		vec3 _front;
		vec3 _up;
		vec3 _right;

		mat4 _viewMatrix;

		int _viewMatrixLocation;

		void updateViewMatrixUniformData();

	public:
		Camera(Shader* shader);
		~Camera();

		void addCameraPosition(vec3 value);

		vec3 getFront();
		vec3 getUp();

		float getCameraSpeed();

		void updateViewMatrix();
	};
}

#endif