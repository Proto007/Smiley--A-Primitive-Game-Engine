#pragma once
#include "pch.h"
#include "Shader.h"
#include "Sprite.h"
#include "RendererImplementation.h"
#include "SmileyUtils.h"
namespace Smiley {
	class SMILEY_API Renderer
	{
	public:
		static void Init();
		static void Draw(Sprite& sprite, int xPos, int yPos, int width, int height, Shader& shader);
		static void ClearFrame();
		static void ShutDown();
	private:
		Renderer();
		inline static Renderer* mInstance{ nullptr };
		inline static std::unique_ptr<RendererImplementation> mImplementation;
	};
}