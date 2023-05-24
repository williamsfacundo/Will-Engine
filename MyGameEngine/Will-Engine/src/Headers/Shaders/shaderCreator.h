#ifndef SHADER_CREATOR
#define SHADER_CREATOR

#include <string>

using namespace std;

namespace WillEngine
{
	class ShaderCreator
	{
	private:
		//unsigned int _shaderProgram;

		//int _vertexColorLocation;

		static string getShaderSourceCode(const char* shaderSourceCodePath);

		static unsigned int compileShader(const char* shaderSourceCode, bool isVertexShader);

		static unsigned int linkShaders(unsigned int vertexShaderId, unsigned int fragmentShaderId);

	public:
		//ShaderCreator();
		//~ShaderCreator();		

		static unsigned int generateShaderProgramFromFiles(const char* vertexPath, const char* fragmentPath);

		//void getColorUniform();

		//void updateColorUniform();

		//void useShaderProgram();
	};
}

#endif