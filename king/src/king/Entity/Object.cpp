
#include <king\Core\Object.hpp>
//#include "Type.hpp"

namespace king {

	Object::Object() {

		_id = 0;
		_type = "";

	}
	
	unsigned int Object::getID() {

		return _id;

	}

	std::string Object::getType() {

		return _type;

	}

}