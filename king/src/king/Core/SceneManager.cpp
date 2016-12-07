
#include <king/Core/SceneManager.hpp>
#include <assert.h>

namespace king {

	SceneManager::SceneManager() {

	}

	SceneManager::~SceneManager() {

		std::map<int, Scene *>::iterator it;

		// Delete all our dropped states
		while (!_stackCollection.empty())
		{
			it = _stackCollection.begin();

			// Retrieve the currently active state
			Scene* scene = it->second;//_stackCollection.back();

			// Pop the currently active state off the stack
			_stackCollection.erase(it);

			// Pause the currently active state
			//anState->Pause();


			// De-initialize the state

			
				scene->destroy();

				// Handle the cleanup before we pop it off the stack
				//anState->Cleanup();

				// Just delete the state now
				delete scene;

				// Don't keep pointers around we don't need
				scene = NULL;
			

			//it++;
		}

		/*while (!_stackActive.empty())
		{
			// Retrieve the currently active state
			Scene * scene = _stackActive.back();

			// Pop the currently active state off the stack
			_stackActive.pop_back();

			// Pause the currently active state
			//anState->Pause();

			// De-initialize the state
			scene->destroy();

			// Handle the cleanup before we pop it off the stack
			//anState->Cleanup();

			// Just delete the state now
			delete scene;

			// Don't keep pointers around we don't need
			scene = NULL;
		}*/



		//std::map<int, Scene *>::iterator _itType;


		/*for (it_type iterator = m.begin(); iterator != m.end(); iterator++) {
			// iterator->first = key
			// iterator->second = value
			// Repeat if you also want to iterate through the second map.
		}*/

		

		// Clear pointers we don't need anymore
		//mApp = NULL;
	


	}

	void registerApp();



	Scene * SceneManager::getActiveScene() {

		return _stackActive.back();

	}

	int SceneManager::getSceneCount() {

		return _stackCollection.size();

	}

	int SceneManager::getActiveSceneCount() {

		return _stackActive.size();

	}

	Scene * SceneManager::getScene(int id) {

		auto found = _stackCollection.find(id);
		//If the state doesn't return false
		if (found == _stackCollection.end())
			return nullptr;
		else
			return found->second;

	}

	Scene * SceneManager::getScene(std::string name) {

		auto found = _sceneByName.find(name);
		//If the state doesn't return false
		if (found == _sceneByName.end())
			return nullptr;
		else
			return getScene(found->second);

	}


	bool SceneManager::isEmpty() {

		return _stackCollection.empty();

	}

	bool SceneManager::hasActiveScene() {

		return _stackActive.empty();

	}

	bool SceneManager::addScene(Scene * scene, std::string name) {

		//Scene * s = scene;


		auto found = _sceneByName.find(name);
		//If the state doesn't return false
		if (found == _sceneByName.end()) {
			

			int id = _stackCollection.size();

			scene->_sceneID = id;

			_stackCollection.insert(std::make_pair(id, scene));
			_sceneByName.insert(std::make_pair(name, id));
			//scene.reset();

			return true;

		}
		else {
			return false; // this scene has been added
		
		}
		

		
	}

	bool SceneManager::removeScene(int id) {

		return true;

	}

	

	bool SceneManager::setScene(int id) {


		auto found = _stackCollection.find(id);
		//If the state doesn't return false
		if (found == _stackCollection.end())
			return false; // scene not found
		else {

			if (_stackActive.empty()) {

				Scene * scene = found->second;

				_currentScene = scene;

				scene->start();

				_stackActive.push_back(found->second);


			}
			else {

				std::vector<Scene *>::iterator it;

				// Find the state that matches theStateID
				for (it = _stackActive.begin(); it < _stackActive.end(); it++)
				{
					if ((*it)->_sceneID == id) {
						
					}
				}
				
			}

			return true;

			/*if (id == found->first) {

				// Add the new active state
				_stackActive.push_back(found->second);

			}
			else
				return false;
			

			return true;*/
		}

	}

	bool SceneManager::setScene(std::string name) {

		auto found = _sceneByName.find(name);
		//If the state doesn't return false
		if (found == _sceneByName.end())
			return false; // scene has been added
		else {

			return setScene(found->second);

		}

	}

}