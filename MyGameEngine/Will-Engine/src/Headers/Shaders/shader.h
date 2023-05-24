#ifndef SHADER_H
#define SHADER_H

namespace WillEngine
{
	class Shader
	{
	private:
		unsigned int _shaderId;

		int _vertexColorLocation;

	public:
		Shader(const char* vertexShaderSourcePath, const char* fragmentShaderSourcePath);
		~Shader();

		void getColorUniform();

		void updateColorUniform();

		void useShaderProgram();
	};
}

#endif