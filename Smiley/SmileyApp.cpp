#include "pch.h"
#include "SmileyApp.h"
namespace Smiley {
	void SmileyApp::Run() {
		std::cout << "Smiley is walking..." << std::endl;
		mGameWindow.CreateWindow(800, 600, "Test");
		while (true) {
			OnUpdate();
			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();
		}
	}
	void SmileyApp::OnUpdate() {

	}
	SmileyApp::SmileyApp() {
	
	}
}
