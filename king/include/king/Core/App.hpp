
#include <SFML\Graphics.hpp>
#include <string>

#include <king\Core\Time.hpp>
#include <king\Core\SceneManager.hpp>
#include <king\Core\Hierarchy.hpp>
#include <king\Render\RenderQueue.hpp>
/*#include "Random.hpp"
#include "AssetManager.hpp"
#include "ResourcesLoader.hpp"*/

#ifndef KING_APP_HPP
#define KING_APP_HPP

namespace king {

	class App {

	private:

		bool _isRunning;
		void clear();
		void initializeTypes();

		sf::RenderWindow * _window;
		system::Hierarchy & _hierarchy;
		
		Time _time;
		//adv::AssetManager * _assets;
		//adv::ResourcesLoader * _res;

		void onPreUpdate();
		void onUpdate();
		void onRender();

	public:

		App();
		~App();
		bool init(std::string appName, int windowWidth = 800, int windowHeight = 600);
		void run();
		void quit();
		bool isRunning();
		SceneManager scene;
		system::RenderQueue & render;
		

	};

}

#endif