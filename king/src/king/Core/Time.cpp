
#include <king\Core\Time.hpp>

float Time::_deltaTime = 0;

Time::Time(float desiredFPS)  { /*: deltaTime(_deltaTime)*/

	//deltaTime = _deltaTime;
	_clock.restart();
	_timePerFrame = sf::seconds(1.f / desiredFPS);
	_lastTime.Zero;
	//Time::_fixedDeltaTime = 0;
	

}

void Time::UpdateTimers() {


	sf::Time now = _clock.getElapsedTime();
	_elapesedTime = now.asSeconds();
	_deltaTime = _elapesedTime - _lastTime.asSeconds();
	_lastTime = now;

	//Time::_deltaTime = _elapesedTime - _deltaTime;
	

	//deltaTime(_deltaTime);

}

/*float Time::fixedDeltaTime() {

	return _fixedDeltaTime;

}*/

float Time::deltaTime() {

	return _deltaTime;

}


/*float Time::DeltaTime() {

	return _deltaTime;

}*/

	