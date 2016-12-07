
#include <king/Entity/GameObject.hpp>



namespace king {

	GameObject::GameObject() : node (this) {

		_name = "New GameObject";

	}

	GameObject::GameObject(std::string name) : node(this) {

		_name = name;
		

	}

	GameObject::~GameObject() {

	}

	void GameObject::setName(std::string name) {

		_name = name;

	}

	std::string GameObject::getName() {

		return _name;

	}

	bool GameObject::getActive() {

		return _active;

	}

	void GameObject::setActive(bool active) {

		_active = active;

	}

	/*void GameObject::_updateChilds() {

		// parent
		this->update();

		if (this->getChildCount() > 0) {
			for (int i = 0; i < this->getChildCount(); i++) {

				if (this->getChild(i)->getActive()) {
					this->getChild(i)->update();

					this->getChild(i)->_updateChilds();
				}
			}
		}

	}*/


	/*GameObject * GameObject::create(GameObject * gameObject) {

		if (gameObject == nullptr)
			gameObject = new GameObject();

		return gameObject;

	}*/

}