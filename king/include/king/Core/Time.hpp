
#ifndef KING_TIME_HPP
#define KING_TIME_HPP

#include <SFML\System.hpp>

class Time {

private:
	sf::Clock _clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time _timePerFrame;
	sf::Time _lastTime;
	
	//static float _fixedDeltaTime;
	float _elapesedTime;
	static float _deltaTime;

protected:

	
	

public:


	Time(float desiredFPS = 60.0f);
	void UpdateTimers();
	//static float fixedDeltaTime();
	static float deltaTime();
	
};

#endif