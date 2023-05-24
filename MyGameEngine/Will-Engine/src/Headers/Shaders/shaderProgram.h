#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

#include <string>

using namespace std;

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

		string getShaderSourceCode(const char* shaderSourceCodePath);

		unsigned int compileShader(const char* shaderSourceCode, bool isVertexShader);

		void getColorUniform();

		void updateColorUniform();

		void useShaderProgram();
	};
}

#endif