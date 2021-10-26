#include "pch.h"
#include "SmileyApp.h"
#include "GLFW/glfw3.h"
namespace Smiley {
	void SmileyApp::Run() {
		std::cout << "Smiley is walking..." << std::endl;
		glfwInit();
		mGameWindow.CreateWindow(800, 600, "Test");
		while (true) {
			OnUpdate();
			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();
			glfwPollEvents();
		}
	}
	void SmileyApp::OnUpdate() {

	}
	SmileyApp::SmileyApp() {
	
	}
}
