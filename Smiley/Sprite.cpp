#include "pch.h"
#include "Sprite.h"
#include "OpenGLimpl/OpenGLSprite.h"
namespace Smiley {
	Sprite::Sprite() {
#ifdef SMILEY_OPENGL
	mSpriteImplementation = std::unique_ptr<SpriteImplementation>{ new OpenGLSprite };	
#else
	#only_OpenGL_is_supported_for_now
#endif
	}
	void Sprite::LoadImage(const std::string& picFile) {
		mSpriteImplementation->LoadImage(picFile);
	}
	int Sprite::GetWidth() const {
		return mSpriteImplementation->GetWidth();
	}
	int Sprite::GetHeight() const {
		return mSpriteImplementation->GetHeight();
	}
	void Sprite::Bind() {
		mSpriteImplementation->Bind();
	}
}