#ifndef DELTA_TIME_H
#define DELTA_TIME_H

namespace WillEngine
{
	class DeltaTime
	{
	private:		
		static float _currentFrameTime;
		static float _lastFrameTime;
		static float _deltaTime;

	public:
		static void updateDeltaTime();

		static float getDeltaTime();

	};
}

#endif