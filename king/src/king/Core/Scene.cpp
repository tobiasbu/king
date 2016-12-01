
#include <king/Core/Scene.hpp>

namespace king {

	Scene::Scene() {

		_isActive = false;
		_isLoaded = false;
		_sceneID = -1;

	}

	bool Scene::isLoaded() {

		return _isLoaded;

	}

	int Scene::getSceneID() {

		return _sceneID;

	}

	bool Scene::isActive() {

		return _isActive;

	}

}