#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>

#include "Enums/camera_movement_enum.h"
#include "Shaders/shader.h"
#include "window.h"

using namespace glm;

namespace WillEngine
{
	//Idea: tener una camara que sea "estatica"
	//Y luego tener una camara que hereda de la camara estatica que tenga funcionalidades que el usuario
	//Pueda utilizar para simular el movimiento de un jugador 
	class Camera
	{
	private:
		const float _cameraMoveSpeed = 2.0f;

		const float _cameraMouseSensitivity = 0.1f;
		
		const vec3 WorldOrigin = vec3(0.0f, 0.0f, 0.0f);

		const vec3 WorldRight = vec3(1.0f, 0.0f, 0.0f);

		const vec3 WorldUp = vec3(0.0f, 0.1f, 0.0f);

		const vec3 WorldFront = vec3(0.0f, 0.0f, -1.0f);

		Window* _window;

		vec3 _position;

		vec3 _right;
		vec3 _up;
		vec3 _front;

		vec3 _lookDirection;

		mat4 _viewMatrix;

		CameraMovementEnum _horizontalKeyboardInputEnum;
		CameraMovementEnum _verticalKeyboardInputEnum;

		int _viewMatrixLocation;		

		double _mouseXPos;
		double _mouseYPos;

		double _lastMouseXPos;
		double _lastMouseYPos;

		float _mouseXOffset;
		float _mouseYOffset;

		float _yaw;
		float _pitch;

		bool _shouldUpdateViewMatrix;
		bool _firstMouse;

		void updateViewMatrixUniformData();

	public:
		Camera(Shader* shader, Window* window);
		~Camera();

		void addCameraPosition(vec3 value);

		vec3 getFront();
		vec3 getUp();

		float getCameraSpeed();

		void updateViewMatrix();

		void inputCameraMovement();

		void updateCameraMovement();

		void updateCameraKeyboardMovement();

		void updateCameraMouseMovement();
	};
}

#endif