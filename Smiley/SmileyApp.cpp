#include "pch.h"
#include "SmileyApp.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_img.h"

namespace Smiley {
	void SmileyApp::Run() {
		SMILEY_LOG("Smiley is walking...");
		mGameWindow.CreateWindow(800, 600, "Test");
		
		Renderer::Init();
		
		//Shaders
		Smiley::Shader myShader;
		myShader.Load("C:/Users/sadab/Desktop/Smiley/F21_Sadab_Hafiz/Smiley/Assets/Shaders/myVertexShader.glsl", 
			"C:/Users/sadab/Desktop/Smiley/F21_Sadab_Hafiz/Smiley/Assets/Shaders/myFragmentShader.glsl");
		myShader.SetVec2IntUniform("screenSize", mGameWindow.GetWindowWidth(), mGameWindow.GetWindowHeight());
		//Texture
		Smiley::Sprite ichigo;
		ichigo.LoadImage("C:/Users/sadab/Desktop/Smiley/F21_Sadab_Hafiz/Smiley/Assets/Textures/ichigo.png");
		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;
		while (true) {
			Renderer::ClearFrame();
			OnUpdate();
			Renderer::Draw(ichigo, 100, 50, ichigo.GetWidth(), ichigo.GetHeight(),myShader);
			std::this_thread::sleep_until(mTimeOfNextFrame);
			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();
			mTimeOfNextFrame += mFrameDuration;
		}
		Renderer::ShutDown();
	}
	void SmileyApp::OnUpdate() {

	}
	SmileyApp::SmileyApp() {
	
	}
}
