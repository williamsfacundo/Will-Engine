#include "Objects/transform.h"

#include <glm.hpp>

using namespace glm;

namespace WillEngine
{
	Transform::Transform()
	{
		setDefaultTransform();
	}

	Transform::Transform(vec3 position)
	{
		setDefaultTransform();

		setLocalPosition(position);
	}

	Transform::Transform(vec3 position, vec3 rotation, vec3 scale)
	{
		setDefaultTransform();

		setLocalPosition(position);
		setLocalRotation(rotation);
		setLocalScale(scale);
	}

	Transform::~Transform()
	{

	}

	void Transform::setLocalPosition(vec3 newPosition)
	{
		_localPosition = newPosition;
	}

	void Transform::setLocalRotation(vec3 newRotation)
	{
		_localRotation = newRotation;
	}

	void Transform::setLocalScale(vec3 newScale)
	{
		_localScale = newScale;
	}

	void Transform::setLocalRotationX(float value)
	{
		_localRotation.x = value;
	}

	void Transform::setLocalRotationY(float value)
	{
		_localRotation.y = value;
	}
	
	void Transform::setLocalRotationZ(float value)
	{
		_localRotation.z = value;
	}

	void Transform::addLocalPosition(vec3 value)
	{
		_localPosition += value;
	}

	void Transform::addLocalRotation(vec3 value)
	{
		_localRotation += value;
	}

	void Transform::addLocalScale(vec3 value)
	{
		_localScale += value;
	}

	void Transform::addLocalXRotation(float value)
	{
		_localRotation.x += value;
	}

	void Transform::addLocalYRotation(float value)
	{
		_localRotation.y += value;
	}
	
	void Transform::addLocalZRotation(float value)
	{
		_localRotation.z += value;
	}

	void Transform::setLocalRight(vec3 newRight)
	{
		_localRight = newRight;
	}

	void Transform::setLocalUp(vec3 newUp)
	{
		_localUp = newUp;
	}

	void Transform::setLocalFront(vec3 newFront)
	{
		_localFront = newFront;
	}

	void Transform::setLocalFrontX(float value)
	{
		_localFront.x = value;
	}

	void Transform::setLocalFrontY(float value)
	{
		_localFront.y = value;
	}

	void Transform::setLocalFrontZ(float value)
	{
		_localFront.z = value;
	}

	void Transform::setDefaultTransform()
	{
		setLocalPosition(WorldOrigin);
		setLocalRotation(DefaultRotation);
		setLocalScale(DefaultScale);

		setLocalRight(WorldRight);
		setLocalUp(WorldUp);
		setLocalFront(WorldFront);
	}

	vec3 Transform::getLocalPosition()
	{
		return _localPosition;
	}

	vec3 Transform::getLocalRotation()
	{
		return _localRotation;
	}

	vec3 Transform::getLocalScale()
	{
		return _localScale;
	}

	vec3 Transform::getLocalRight()
	{
		return _localRight;
	}

	vec3 Transform::getLocalUp()
	{
		return _localUp;
	}
	
	vec3 Transform::getLocalFront()
	{
		return _localFront;
	}

	vec3 Transform::getWorldRight()
	{
		return WorldRight;
	}

	vec3 Transform::getWorldUp()
	{
		return WorldUp;
	}
	
	vec3 Transform::getWorldFront()
	{
		return WorldFront;
	}
}