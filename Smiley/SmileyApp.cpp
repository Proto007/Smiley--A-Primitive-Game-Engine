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
		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;
		while (true) {
			Renderer::ClearFrame();
			OnUpdate();			
			std::this_thread::sleep_until(mTimeOfNextFrame);
			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();
			mTimeOfNextFrame += mFrameDuration;
		}
		Renderer::ShutDown();
	}
	int SmileyApp::GetGameWindowWidth() const {
		return mGameWindow.GetWindowWidth();
	}
	int SmileyApp::GetGameWindowHeight() const{
		return mGameWindow.GetWindowHeight();
	}
	void SmileyApp::OnUpdate() {

	}
	void SmileyApp::OnKeyPressed(KeyPressedEvent& event) {
		SMILEY_LOG(event.GetKeyCode());
	}
	SmileyApp::SmileyApp() {
		mGameWindow.CreateWindow(800, 800, "Game");
		mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});

		Renderer::Init();
	}
}
