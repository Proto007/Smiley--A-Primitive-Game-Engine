#include "pch.h"
#include "OpenGLSprite.h"
#include "stb_img.h"

namespace Smiley {
	OpenGLSprite::OpenGLSprite() {};
	OpenGLSprite::OpenGLSprite(const std::string& picFile) {
		LoadImage(picFile);
	}
	OpenGLSprite::~OpenGLSprite() {
	}
	void OpenGLSprite::LoadImage(const std::string& picFile) {
		unsigned char* image{ nullptr };
		int numChannels{ 0 };
		stbi_set_flip_vertically_on_load(true);
		image= stbi_load(picFile.c_str(), &mWidth, &mHeight, &numChannels, 0);
		//Prints the reason why stbi failed to load image
		if (stbi_failure_reason()) {
			std::cout << stbi_failure_reason()<<std::endl;
		}
		//Throw exception if image is not loaded correctly
		assert(image != nullptr);

		glGenTextures(1,&mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(image);
	}

	int OpenGLSprite::GetWidth() const {
		return mWidth;
	}
	int OpenGLSprite::GetHeight() const {
		return mHeight;
	}
	void OpenGLSprite::Bind() {
		glBindTexture(GL_TEXTURE_2D,mTexture);
	}
}	