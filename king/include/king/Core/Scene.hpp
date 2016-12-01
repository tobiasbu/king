

#ifndef KING_SCENE_HPP
#define KING_SCENE_HPP

#include <king\Core\Object.hpp>

namespace king {

	class SceneManager;

	class Scene : public Object {

		friend class SceneManager;

	private:



		//App * _app;
		bool _isActive;
		bool _isLoaded;
		int _sceneID;

		Scene& operator=(const Scene&); // Intentionally undefined


	public:

		Scene();
		virtual ~Scene() {};

		virtual void preload() {}
		virtual void loading() {}
		virtual void start() {};
		virtual void destroy() {}

		bool isActive();
		bool isLoaded();
		int getSceneID();

	};

}

#endif