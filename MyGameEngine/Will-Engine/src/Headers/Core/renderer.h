#ifndef RENDERER_H
#define RENDERER_H

#include "Shaders/shader.h"
#include "Objects/object.h"
#include "camera.h"

namespace WillEngine
{
	class Renderer
	{
	private:

	public:
		Renderer();
		~Renderer();

		void renderingCommands();

		static void drawObject(Object* object, Camera* camera);
	};
}

#endif