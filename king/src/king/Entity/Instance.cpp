
#include <king/Entity/Instance.hpp>


namespace king {

	GameObject * Instance::create() {

		GameObject * gameObject = new GameObject("New Game Object");

			//system::Hierarchy::getInstance().getChildCount()

		system::Hierarchy::getInstance().addChild(&gameObject->node);

			return gameObject;

	}


	void Instance::destroy(GameObject &) {

	}

}