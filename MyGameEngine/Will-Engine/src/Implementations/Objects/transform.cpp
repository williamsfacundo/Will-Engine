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
}