#ifndef SHADER_CREATOR
#define SHADER_CREATOR

#include <string>

using namespace std;

namespace WillEngine
{
	class ShaderCreator
	{
	private:
		unsigned int _shaderProgram;

		int _vertexColorLocation;

		string getShaderSourceCode(const char* shaderSourceCodePath);

		unsigned int compileShader(const char* shaderSourceCode, bool isVertexShader);

		unsigned int linkShaders(unsigned int vertexShaderId, unsigned int fragmentShaderId);

	public:
		ShaderCreator();
		~ShaderCreator();		

		void generateShaderProgramFromFiles(const char* vertexPath, const char* fragmentPath);

		void getColorUniform();

		void updateColorUniform();

		void useShaderProgram();
	};
}

#endif