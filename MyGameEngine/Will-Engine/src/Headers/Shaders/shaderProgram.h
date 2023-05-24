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

		string getShaderSourceCode(const char* shaderSourceCodePath);

		unsigned int compileShader(const char* shaderSourceCode, bool isVertexShader);

		unsigned int linkShaders(unsigned int vertexShaderId, unsigned int fragmentShaderId);

	public:
		ShaderProgram();
		~ShaderProgram();		

		void generateShaderProgramFromFiles(const char* vertexPath, const char* fragmentPath);

		void getColorUniform();

		void updateColorUniform();

		void useShaderProgram();
	};
}

#endif