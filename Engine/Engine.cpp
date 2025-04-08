#include <Standard/IO.hpp>
#include <Window/Window.hpp>

std::unique_ptr<Window> window{};

int main() {
	WindowCreateInfo wci{};
	wci.title = "CryoMesh Engine";
	wci.width = 800;
	wci.height = 600;
	wci.resizable = true;
	wci.fullscreen = false;
	wci.adaptive_resolution = true;

	window = std::make_unique<Window>();
	size_t pwindow{};

	try {
		pwindow = window->CreateNewWindow(wci);
	}
	catch (const std::exception& e) {
		io::printerr(io::LogLevel::ERROR, "{}", e.what());
	}

	while (!window->ShouldClose(pwindow)) {
		window->Update(pwindow);
	}
}