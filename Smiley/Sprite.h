#pragma once
#include "pch.h"
#include "SmileyUtils.h"
#include "Sprite.h"
#include "SpriteImplementation.h"
namespace Smiley {
	class SMILEY_API Sprite
	{
	public:
		Sprite();
		void LoadImage(const std::string& picFile);
		int GetWidth() const;
		int GetHeight() const;
		void Bind();
	private:
		std::unique_ptr<SpriteImplementation> mSpriteImplementation;
	};
}

