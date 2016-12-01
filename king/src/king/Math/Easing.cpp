
#include <king\Math\Easing.hpp>



namespace king {

	float Easing::easeIn(float t, Type type) {

		switch (type)
		{
			default:
			case Type::Step: return t < 0.5 ? 0 : 1;
			case Type::Linear: return (float)t;
			case Type::Sine: return Sine::in(t);
			case Type::Quadratic: return Power::in(t, 2);
			case Type::Cubic: return Power::in(t, 3);
			case Type::Quartic: return Power::in(t, 4);
			case Type::Quintic: return Power::in(t, 5);
		}

	}

	float Easing::easeOut(float t, Type type) {

		return 0;

	}

	float Easing::easeInOut(float t, Type type) {

		return 0;

	}

	float Easing::easeInOut(float t, Type typeIn, Type typeOut) {

		return 0;

	}

	float Easing::Power::in(double s, int power) {

		return 0;

	}

	float Easing::Power::out(double s, int power) {

		return 0;

	}

	float Easing::Sine::in(float t) {
	
		return sin(t * Math::HALF_PI - Math::HALF_PI) + 1;

	}

	float Easing::Sine::out(float t) {

		return 0;

	}
	

}