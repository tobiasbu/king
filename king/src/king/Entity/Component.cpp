
#include <king/Entity/Component.hpp>

namespace king {

	Component::Component(GameObject * gameObject) {
		_gameObject = gameObject;
	}

	Component::~Component() {

	}

	void Component::setActive(bool active) {

		_active = active;

	}

	bool Component::getActive() {

		return _active;

	}

	GameObject * Component::getGameObject() {

		return _gameObject;

	}
}