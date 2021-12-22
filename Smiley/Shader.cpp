#include "pch.h"
#include "Shader.h"
#include "OpenGLimpl/OpenGLShader.h"
namespace Smiley {
	Shader::Shader() {
#ifdef SMILEY_OPENGL
		mShader = std::unique_ptr<ShaderImplementation>{new OpenGLShader};
#else
		#ONLY OPENGL IS IMPLEMENTED AT THE MOMENT
#endif
	}
	void Shader::Load(const std::string& vertexFile, const std::string& fragmentFile) {
		mShader->Load(vertexFile, fragmentFile);
	}
	void Shader::SetVec2IntUniform(const std::string& unifName, int first, int second) {
		mShader->SetVec2IntUniform(unifName, first, second);
	}
	void Shader::Use() {
		mShader->Use();
	}
}