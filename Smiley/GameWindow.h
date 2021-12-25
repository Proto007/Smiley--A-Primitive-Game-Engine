#pragma once
#include "SmileyUtils.h"
#include "WindowImplementation.h"
#include "pch.h"
#include "Events.h"
namespace Smiley {
	class SMILEY_API GameWindow{
	public:
		GameWindow();
		void CreateWindow(int width, int height, std::string name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;
		void SetKeyPressedCallback(std::function<void(KeyPressedEvent &)>);
	private:
		std::unique_ptr<WindowImplementation> mWindow;
	};
}
