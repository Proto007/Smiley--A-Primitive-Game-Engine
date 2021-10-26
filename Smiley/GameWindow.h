#pragma once
#include "SmileyUtils.h"
#include "WindowImplementation.h"
namespace Smiley {
	class SMILEY_API GameWindow{
	public:
		GameWindow();
		void CreateWindow(int width, int height, std::string name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;
	private:
		WindowImplementation* mWindow;
	};
}
