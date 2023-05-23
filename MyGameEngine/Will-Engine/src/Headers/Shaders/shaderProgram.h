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

		void generateShaderProgramFromFiles(const char* vertexPath, const char* fragmentPath);

		const char* getShaderSourceCode();

		unsigned int compileShader();

		void getColorUniform();

		void updateColorUniform();

		void useShaderProgram();
	};
}

#endif