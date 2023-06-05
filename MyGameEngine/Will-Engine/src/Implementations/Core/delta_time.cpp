#include "Core/delta_time.h"

#include <glew.h>
#include <glfw3.h>

namespace WillEngine
{
	float DeltaTime::_currentFrameTime = 0.0f;
	float DeltaTime::_deltaTime = 0.0f;
	float DeltaTime::_lastFrameTime = 0.0f;

	void DeltaTime::updateDeltaTime()
	{
		_currentFrameTime = glfwGetTime();

		_deltaTime = _currentFrameTime - _lastFrameTime;

		_lastFrameTime = _currentFrameTime;
	}

	float DeltaTime::getDeltaTime()
	{
		return _deltaTime;
	}
}