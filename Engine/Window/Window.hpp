#pragma once

#include <string>

struct WindowCreateInfo {
	std::string title;
	uint32_t width;
	uint32_t height;
	bool resizable;
	bool fullscreen;
	bool adaptive_resolution;
};

class Window {
public:
	size_t CreateNewWindow(WindowCreateInfo& wci);
	void* GetWindowHandle(size_t i);

	bool ShouldClose(size_t i);
	void Update(size_t i);

	~Window();
};