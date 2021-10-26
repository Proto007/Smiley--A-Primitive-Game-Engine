#include "pch.h"
#include "GameWindow.h"
#include "GLFWimpl/GlfwImplementation.h"

namespace Smiley {
	GameWindow::GameWindow() {

#ifdef SMILEY_WINDOWS
		mWindow = new GlfwImplementation();
#elif SMILEY_MAC
		mWindow = new GlfwImplementation();
#elif SMILEY_LINUX
		mWindow = new GlfwImplementation();
#else
	#only_Windows_Linux_Mac_are_supported
#endif

		mWindow->Init();
	}
	void GameWindow::CreateWindow(int width, int height, const std::string name) {
		mWindow->CreateWindow(width, height, name);
	}
	void GameWindow::SwapBuffers() {
		mWindow->SwapBuffers();
	}
	void GameWindow::PollEvents() {
		mWindow->PollEvents();
	}
	int GameWindow::GetWindowWidth() const{
		return mWindow->GetWindowWidth();
	}
	int GameWindow::GetWindowHeight() const{
		return mWindow->GetWindowHeight();
	}
}
