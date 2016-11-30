




#ifndef KING_SCENEMANAGER_HPP
#define KING_SCENEMANAGER_HPP

#include <king\Core\Scene.hpp>
#include <king\Others\NonCopyable.hpp>


#include <memory>
#include <vector>
#include <map>

namespace king {

	class SceneManager : public NonCopyable {

	private:

		//App * _app;
		Scene * _currentScene;

		/// Stack to store the active scenes
		std::vector<Scene*>  _stackActive;

		/// Stack to store the scenes until they properly cleaned up
		//typedef std::map<int, Scene *> StateStack;
		std::map<int, Scene *> _stackCollection;
		std::map<std::string, int> _sceneByName;

	public:
		SceneManager();
		~SceneManager();

		// getters
		
		int getSceneCount();
		int getActiveSceneCount();
		Scene * getScene(int);
		Scene * getScene(std::string);
		Scene * getActiveScene();
		bool isEmpty();
		bool hasActiveScene();

		void registerApp();

		// setters

		bool setScene(std::string);
		bool setScene(int);
		bool addScene(Scene *, std::string);		
		bool removeScene(int);		
		
		

	};

}

#endif