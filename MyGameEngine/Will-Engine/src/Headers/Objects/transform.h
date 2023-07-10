#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm.hpp>

using namespace glm;

namespace WillEngine
{
	class Transform
	{
	private:
		const vec3 WorldOrigin = vec3(0.0f, 0.0f, 0.0f);
		const vec3 DefaultRotation = vec3(0.0f, 0.0f, 0.0f);
		const vec3 DefaultScale = vec3(1.0f, 1.0f, 1.0f);
		const vec3 WorldRight = vec3(1.0f, 0.0f, 0.0f);
		const vec3 WorldUp = vec3(0.0f, 0.1f, 0.0f);
		const vec3 WorldFront = vec3(0.0f, 0.0f, 1.0f);

		vec3 _localPosition;
		vec3 _localRotation; //x(pitch), y(yaw), z(roll)
		vec3 _localScale;

		vec3 _localRight;
		vec3 _localUp;
		vec3 _localFront;		

	public:
		Transform();
		Transform(vec3 position);
		Transform(vec3 position, vec3 rotation, vec3 scale);
		~Transform();

		void setLocalPosition(vec3 newPosition);
		void setLocalRotation(vec3 newRotation);
		void setLocalScale(vec3 newScale);

		void setLocalRight(vec3 newRight);
		void setLocalUp(vec3 newUp);
		void setLocalFront(vec3 newFront);

		void setDefaultTransform();

		vec3 getLocalPosition();
		vec3 getLocalRotation();
		vec3 getLocalScale();

		vec3 getLocalRight();
		vec3 getLocalUp();
		vec3 getLocalFront();
	};
}

#endif