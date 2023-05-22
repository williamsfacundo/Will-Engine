#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

namespace WillEngine
{
	class ShaderProgram
	{
	private:
		unsigned int _shaderProgram;

		int _vertexColorLocation;

	public:
		ShaderProgram();
		~ShaderProgram();
		
		void generateShaderProgram();

		void getColorUniform();

		void updateColorUniform();

		void useShaderProgram();
	};
}

#endif