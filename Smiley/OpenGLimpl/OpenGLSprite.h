#pragma once
#include "SmileyUtils.h"
#include "pch.h"
#include "SpriteImplementation.h"
#include "glad/glad.h"

namespace Smiley
{
	class OpenGLSprite: public SpriteImplementation {
	public:
		OpenGLSprite();
		OpenGLSprite(const std::string& picFile);
		~OpenGLSprite();
		virtual void LoadImage(const std::string& picFile) override;
		virtual int GetWidth() const override;
		virtual  int GetHeight() const override;
		virtual void Bind() override;
	private:
		unsigned int mTexture{ 0 };
		int mWidth{0};
		int mHeight{0};
	};
}