
#include <king\Core\App.hpp>
#include <king\System\Type.hpp>
#include <iostream>

using namespace std;


namespace king {

	App::App() {

	}

	App::~App() {

		_isRunning = false;

	}

	bool App::isRunning() {

		return _isRunning;

	}

	

	bool App::init(std::string appName, int windowWidth, int windowHeight) {

		_window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), appName);

		_window->clear();

		//Random::initialize();

		//_assets = new adv::AssetManager();
		//_res->registerAssetManager(_assets);

		initializeTypes();

		//if (adv::ResourcesLoader::test())
		//std::cout << "eu tenho um assetman aqui " << _assets->count() << std::endl;

		return true;

	}

	void App::run() {

		sf::Texture tex;
		tex.loadFromFile("img//king_ui.png", sf::IntRect(2, 2, 28, 25));
		sf::Sprite sprite;
		tex.setRepeated(true);
	
		sprite.setTexture(tex);
		sprite.setTextureRect(sf::IntRect(0,0,800,24));

		sf::View view;
		view.setSize(_window->getSize().x, _window->getSize().y);
		view.setCenter(_window->getSize().x / 2, _window->getSize().y / 2);

		_isRunning = true;

		// Make sure we have at least one state active
		if (scene.hasActiveScene())
		{
			// Exit with an error since there isn't an active state
			quit();
		}

		

		while (_isRunning && !scene.hasActiveScene() && _window->isOpen()) {

			_time.UpdateTimers();


			sf::Event event;
			while (_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window->close();
				if (event.type == sf::Event::Resized) {
					view.setSize(_window->getSize().x, _window->getSize().y);
					view.setCenter(_window->getSize().x / 2, _window->getSize().y / 2);
					sprite.setTextureRect(sf::IntRect(0, 0, _window->getSize().x, 24));
				}

			}

			_window->clear();
			_window->setView(view);
			//_window.draw(shape);
			_window->draw(sprite);
			_window->display();

		}

		clear();

	}

	// register sfml types and common types of king
	void App::initializeTypes() {

		TypeParseTraits<sf::Texture>::registerType();
		TypeParseTraits<sf::Font>::registerType();

		// register assets managers
		//_assets->registry<sf::Texture>();
		//_assets->registry<sf::Font>();
	//	assets.registry<sf::Texture>();
	//	assets.registry<sf::Font>();

	}

	void App::quit() {

		_isRunning = false;

	}

	void App::clear() {

		if (_window->isOpen()) {

			_window->close();

		}

	}
}