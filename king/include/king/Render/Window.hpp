


#ifndef KING_WINDOW_H
#define KING_WINDOW_H

#include <king\Math\Vector2.hpp>
#include <GLFW\glfw3.h>

namespace king {

	class Window {

	private:

		GLFWwindow * _window;
		Vector2ui _size;

	public:

		Window();
		Vector2ui getSize() const;
		GLFWwindow * getHandle();
		// Constructors

		

	};

}

#endif