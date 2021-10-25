#pragma once
#include "SmileyUtils.h"
namespace Smiley {

	class SMILEY_API SmileyApp
	{
	public:
		// Starts the game loop
		void Run();
		// Used in each run of the game loop to update game screen 
		virtual void OnUpdate();
	protected:
		SmileyApp();
	private:

	};

}
