
#ifndef KING_GLCONTROL_H
#define KING_GLCONTROL_H

// include GLEW and new version of GL on Windows
#include <GL/glew.h> 
#include <string>

namespace king {

	class GLControl {

	private:

		// OpenGL Data
		const GLubyte * _GLversion;

		// Private Functions

		bool initGLEW();

	public:


		bool init();
		std::string getString(GLenum str);

	};

}

#endif