
#ifndef KING_RANDOM_HPP
#define KING_RANDOM_HPP


namespace king {

	class Random {

		friend class App;

	private:
		static unsigned int _seed;

		/*int operator() ();
		void seed(int seed);*/
		static void initialize();

	public:
		
		static int range(int min, int max);
		static float range(float min, float max);
		static void setRandomSeed(unsigned int seedValue);
		static unsigned int getSeed();
		
		

	};

}

#endif