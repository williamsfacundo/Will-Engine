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
		const float _cameraSpeed = 2.0f;
		
		Window* _window;

		vec3 _position;

		vec3 _front;
		vec3 _up;
		vec3 _right;

		mat4 _viewMatrix;

		CameraMovementEnum _keyboardInputEnum;

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

		void updateCameraMouseMovement();
	};
}

#endif