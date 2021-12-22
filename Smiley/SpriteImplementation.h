#pragma once
#include "pch.h"
namespace Smiley {
	class SpriteImplementation {
	public:
		virtual void LoadImage(const std::string& picFile)=0;
		virtual int GetWidth() const=0;
		virtual int GetHeight() const=0;
		virtual void Bind() = 0;
		virtual ~SpriteImplementation() {};
	};
}