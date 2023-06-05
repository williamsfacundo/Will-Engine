#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>

#include "Shaders/shader.h"
#include "window.h"

using namespace glm;

namespace WillEngine
{
	class Camera
	{
	private:
		const float _cameraSpeed = 2.0f;
		
		Window* _window;

		vec3 _position;

		vec3 _front;
		vec3 _up;
		vec3 _right;

		mat4 _viewMatrix;

		int _viewMatrixLocation;

		bool _firstMouse;

		float _lastMouseXPos;
		float _lastMouseYPos;
		double _mouseXPos;
		double _mouseYPos;

		float _yaw;
		float _pitch;

		void updateViewMatrixUniformData();

	public:
		Camera(Shader* shader, Window* window);
		~Camera();

		void addCameraPosition(vec3 value);

		vec3 getFront();
		vec3 getUp();

		float getCameraSpeed();

		void updateViewMatrix();

		void updateCameraMovement();
	};
}

#endif