#include "Window.hpp"

#include <vector>
#include <stdexcept>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

std::vector<GLFWwindow*> windows;

size_t Window::CreateNewWindow(WindowCreateInfo& wci) {
	bool _parentwindow{};
	
	if (windows.empty()) {
		_parentwindow = true;
	}

	if (_parentwindow) {
		if (!glfwInit()) {
			throw std::runtime_error("Failed to initialize window runtime!");
		}
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, wci.resizable);

	GLFWwindow* _window;
	if (wci.fullscreen) {
		GLFWmonitor* _monitor = glfwGetPrimaryMonitor();

		const GLFWvidmode* _mode = glfwGetVideoMode(_monitor);
		
		if (wci.adaptive_resolution) {
			_window = glfwCreateWindow(_mode->width, _mode->height, wci.title.c_str(), _monitor, nullptr);
		}
		else {
			_window = glfwCreateWindow(wci.width, wci.height, wci.title.c_str(), _monitor, nullptr);
		}
	}
	else {
		_window = glfwCreateWindow(wci.width, wci.height, wci.title.c_str(), nullptr, nullptr);
	}

	if (!_window) {
		throw std::runtime_error("Failed to create window!");
	}

	windows.push_back(_window);

	return windows.size() - 1;
}

void* Window::GetWindowHandle(size_t i) {
	return static_cast<void*>(windows[i]);
}

bool Window::ShouldClose(size_t i) {
	return glfwWindowShouldClose(windows[i]);
}

void Window::Update(size_t i) {
	glfwSwapBuffers(windows[i]);
	glfwPollEvents();
}

Window::~Window() {
	for (GLFWwindow* _window : windows) {
		glfwDestroyWindow(_window);
	}

	glfwTerminate();
}