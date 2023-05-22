#ifndef RENDERER_H
#define RENDERER_H

#include "Shaders/shaderProgram.h"
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

		void drawObject(ShaderProgram* shaderProgram, Object* object);
	};
}

#endif