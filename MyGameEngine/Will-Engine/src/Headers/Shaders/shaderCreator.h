#ifndef SHADER_CREATOR
#define SHADER_CREATOR

#include <string>

using namespace std;

namespace WillEngine
{
	class ShaderCreator
	{
	private:
		static string getShaderSourceCode(const char* shaderSourceCodePath);

		static unsigned int compileShader(const char* shaderSourceCode, bool isVertexShader);

		static unsigned int linkShaders(unsigned int vertexShaderId, unsigned int fragmentShaderId);

	public:
		static unsigned int generateShaderProgramFromFiles(const char* vertexPath, const char* fragmentPath);		
	};
}

#endif