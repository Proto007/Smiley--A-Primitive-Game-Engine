#include "pch.h"
#include "SmileyApp.h"
#include "GLFW/glfw3.h"
namespace Smiley {
	void SmileyApp::Run() {
		std::cout << "Smiley is walking..." << std::endl;
		GLFWwindow* window;
		glfwInit();
		window = glfwCreateWindow(800, 600, "Test",NULL,NULL);
		while (true) {
			OnUpdate();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	void SmileyApp::OnUpdate() {

	}
	SmileyApp::SmileyApp() {
	
	}
}
