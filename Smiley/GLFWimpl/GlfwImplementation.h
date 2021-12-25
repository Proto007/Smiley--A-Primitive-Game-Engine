#pragma once
#include "WindowImplementation.h"
#include "GLFW/glfw3.h"
namespace Smiley {
	class GlfwImplementation : public WindowImplementation {
	public:
		virtual void Init() override;
		virtual void CreateWindow(int width, int height, const std::string& name) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWindowWidth() const override;
		virtual int GetWindowHeight() const override;
		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func);
	private:
		GLFWwindow* mWindow;
		struct CallbackFunctions {
			std::function<void(KeyPressedEvent &)> KeyPressedCallback;
		} mCallbacks;
	};
}