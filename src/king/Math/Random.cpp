
#include <king\Math\Random.hpp>
#include <ctime>
#include <time.h> 
#include <cstdlib>



namespace king {

	unsigned int Random::_seed = 0;

	void Random::initialize() {

		_seed = time(NULL);
		srand(_seed);

	}

	/*Random::operator() ()
	{

	}*/

	/*int Random::operator() () {

		const unsigned int a = 1967773755;

		_seed = a * (_seed & 0xffffffff) + (_seed >> 32);
		return static_cast<int>(_seed);

	}

	void Random::seed(int seed) {

		_seed = seed + !seed;

	}*/

	int Random::range(int min, int max) {

		_seed = rand();
		return _seed % (max - min) + min;

	}

	float Random::range(float min, float max) {

		_seed = rand();
		return (min + static_cast <float> (_seed) / (static_cast <float> (RAND_MAX / (max - min))));

	}

	void Random::setRandomSeed(unsigned int seedValue) {

		_seed = seedValue;
		srand(_seed);

	}

	unsigned int Random::getSeed() {

		return _seed;

	}
}