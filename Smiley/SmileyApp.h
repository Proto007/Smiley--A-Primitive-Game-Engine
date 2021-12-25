#pragma once
#include "SmileyUtils.h"
#include "GameWindow.h"

#define FRAMES_PER_SECOND 30
namespace Smiley {

	class SMILEY_API SmileyApp
	{
	public:
		// Starts the game loop
		void Run();
		// Used in each run of the game loop to update game screen 
		virtual void OnUpdate();
		virtual void OnKeyPressed(KeyPressedEvent& event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;
	protected:
		SmileyApp();
	private:
		GameWindow mGameWindow;
		std::chrono::steady_clock::time_point mTimeOfNextFrame;
		std::chrono::milliseconds mFrameDuration{ 1000/FRAMES_PER_SECOND };
	};

}
