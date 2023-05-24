#ifndef RENDERER_H
#define RENDERER_H

#include "Shaders/shaderCreator.h"
#include "Objects/object.h"

namespace WillEngine
{
	class Renderer
	{
	private:

	public:
		Renderer();
		~Renderer();

		void renderingCommands();

		void drawObject(ShaderCreator* shaderProgram, Object* object);
	};
}

#endif