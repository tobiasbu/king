
#include <king\Render\GL\GLControl.hpp>
#include <king\Utils\StringUtils.hpp>
#include <stdarg.h> // used by log functions to have variable number of args
#include <stdio.h>
#include <time.h>

namespace king {

	bool GLControl::initGLEW() {

		glewExperimental = GL_TRUE;


		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "Failed to initialize GLEW\n");
			return -1;
		}

		// tell GL to only draw onto a pixel if the shape is closer to the viewer


		return true;

	}

	bool GLControl::init() {

		if (!initGLEW())
			return false;

		// get version info
		const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
		_GLversion = glGetString(GL_VERSION);

		return true;

	}

	std::string GLControl::getString(GLenum index) {

		const GLubyte * text = glGetString(index);
		return StringUtils::charToString(text);

	}

}