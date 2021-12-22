#pragma once
#include "SmileyUtils.h"
#include "pch.h"
#include "ShaderImplementation.h"
namespace Smiley{
	class SMILEY_API Shader
	{
	public:
		Shader();
		void Load(const std::string& vertexFile, const std::string& fragmentFile);
		void SetVec2IntUniform(const std::string& unifName,int first, int second);
		void Use();
	private:
		std::unique_ptr<ShaderImplementation> mShader;
	};
}