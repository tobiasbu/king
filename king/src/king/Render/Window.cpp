
#include <king\Render\Window.hpp>


namespace king {

	Window::Window() {}

	Vector2ui Window::getSize() const {

		return _size;

	}

	GLFWwindow * Window::getHandle() {

		return _window;

	}

}