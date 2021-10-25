#include "Smiley.h"

// Entry point
class MyGameApp : public Smiley::SmileyApp {
	// User must override the OnUpdate virtual method
	void OnUpdate() override {
	
	}
};

START_SMILEY_GAME(MyGameApp);