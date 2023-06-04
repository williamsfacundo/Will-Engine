#ifndef RENDERER_H
#define RENDERER_H

#include <glm.hpp>

#include "Shaders/shader.h"
#include "Objects/object.h"
#include "camera.h"

using namespace glm;

namespace WillEngine
{
	class Renderer
	{
	private:
		mat4 _projectionMatrix;

		int _projectionMatrixLocation;

		void updateProjectionMatrixUniformData();

	public:
		Renderer(Shader* shader);
		~Renderer();

		void renderingCommands();

		void drawObject(Object* object, Camera* camera);
	};
}

#endif