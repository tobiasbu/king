


#ifndef KING_EASING_HPP
#define KING_EASING_HPP

#include <king\Math\Math.hpp>
#include <math.h>

namespace king {

	static class Easing {

	public:

		enum Type {
			Step,
			Linear,
			Sine,
			Quadratic,
			Cubic,
			Quartic,
			Quintic,
			Expo,
			Circ,
			Back,
			Elastic,
			Bounce
		};

		static class Power {
		public:
			static float in(double s, int power);
			static float out(double s, int power);
		};

		static class Sine {
		public:
			static float in(float t);
			static float out(float t);
		};

		static float easeIn(float t, Type type);
		static float easeOut(float t, Type type);
		static float easeInOut(float t, Type type);
		static float easeInOut(float t, Type typeIn, Type typeOut);

		
	
	};
}

#endif