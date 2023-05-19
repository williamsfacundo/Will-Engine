#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

namespace WillEngine
{
	class ShaderProgram
	{
	private:
		unsigned int _shaderProgram;

	public:
		ShaderProgram();
		~ShaderProgram();
		
		void generateShaderProgram();

		void useShaderProgram();
	};
}

#endif