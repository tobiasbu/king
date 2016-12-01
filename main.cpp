
#include <king\King.hpp>
#include "SceneSplash.h"

#include <iostream>

int main()
{
	king::App app;

	//using namespace king;

	//pointer->count();
	//std::string type = king::TypeParseTraits<sf::Font>::registerType();//.registerType(TypeParseTraits<sf::Font>());
	//king::TypeParseTraits<sf::Font>::registerType();
	//king::TypeParseTraits<sf::Font>::registerType();
	
	//std::cout << king::TypeParseTraits<sf::Texture>::name() << std::endl;
	
	//.asset.registry(TypeParseTraits<sf::Texture>() );
	/*app.asset.loadAsset("img\\king_ui.png");
	Asset * asset = app.asset.getAsset("king_ui", king::AssetType::Texture);

	
	
	std::cout << asset->getPath() << " " << asset->getName()  << std::endl;

	sf::Texture * tex = (sf::Texture *)asset->getData();
	std::cout << tex->getSize().x << std::endl;*/
	//dynamic_cast <sf::Texture *>(&(*asset->getData()));

	//king::SceneManager scene;

	//app._scene = scene;

	if (app.init("KING",1280,720)) {

		king::Vector3f test;
		king::Vector2f test2(0,5240);
		king::Matrix4 mat(1.0f);

		
		//test = (test + test2);

		
		//test.set(1, 2, 3);
		//test = 1;

		//test += (float)1;

		//test = king::StringUtils::parseVector3f(test2.toString());

		std::cout << test2[1] << "\n " << mat.getRow(0).toString() << std::endl;

		app.scene.addScene(new SceneSplash(), "splash");
		app.scene.setScene("splash");
		//ResourceManager<sf::Texture> * pointer = app.assets.getResourceManager<sf::Texture>();

		//std::cout << pointer->count() << std::endl;
		//std::cout << TypeParseTraits<T>().name() << endl;

		app.run();

	}

	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	return 0;
}