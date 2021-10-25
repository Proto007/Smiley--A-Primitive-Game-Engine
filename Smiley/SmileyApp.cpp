#include "pch.h"
#include "SmileyApp.h"

namespace Smiley {
	void SmileyApp::Run() {
		std::cout << "Smiley is walking..." << std::endl;
		while (true) {
			OnUpdate();
		}
	}
	void SmileyApp::OnUpdate() {

	}
	SmileyApp::SmileyApp() {
	
	}
}
