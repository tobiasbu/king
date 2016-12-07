
#include <king/Core/Hierarchy.hpp>
#include <king/Entity/GameObject.hpp>

namespace king {
	namespace system {

		Hierarchy::Hierarchy() {

			
		}

		void Hierarchy::onUpdate() {

			for (int i = 0; i < _childs.size(); i++) {
				if (_childs[i]->getGameObject()->getActive()) {

					// Update self
					_childs[i]->getGameObject()->update();

					// Update childrens
					_childs[i]->onUpdate();
				}
			}
		}

		void Hierarchy::onEndUpdate() {


		}

		void Hierarchy::onFixedUpdate() {


		}

		Hierarchy::~Hierarchy() {

			clear();

		}

	
		

		/*void Hierarchy::add(GameObject * gameObject) {

			if (gameObject == nullptr)
				gameObject = new GameObject();

			_gameObjects.push_back(gameObject);

		}
		void Hierarchy::remove(int index) {

			delete _gameObjects[index];
			_gameObjects.erase(_gameObjects.begin() + index);
		}
	
		/*void Hierarchy::remove(GameObject * gameObject) {

			std::vector<GameObject *>::iterator it; //_gameObjects
			_gameObjects.at(gameObject);
			//_gameObjects.erase(gameObject);

		}

		void Hierarchy::onUpdate() {

	
			for (int i = 0; i < _gameObjects.size(); i++) {
				if (_gameObjects[i]->getActive())
					_gameObjects[i]->_updateChilds();
			}

		}


		void Hierarchy::onEndUpdate() {

		}
		void Hierarchy::onFixedUpdate() {

		}*/

		void Hierarchy::clear() {

			/*std::vector<GameObject *>::iterator it = _gameObjects.end();

			while (!_gameObjects.empty()) {
				delete (*it);
				it--;
			}

			_gameObjects.clear();*/
		}
	}
}