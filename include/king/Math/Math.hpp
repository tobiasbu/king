
#ifndef KING_MATH_HPP
#define KING_MATH_HPP

#include <king\Math\Vector2.hpp>

namespace king {

	static class Math {

	public:
		static const double PI;
		static const double HALF_PI; // PI / 2
		static const double degToRad;
		static const double radToDeg;

		static int factorial(int n);
		static double sin(double x);
		static double cos(double x);
		static double power(double x, int y);

		static float lerp(float from, float to, float t);
		static Vector2f lerp(Vector2f from, Vector2f to, float t);
		static double degreesToRadians(double);
		static double radiansToDegrees(double);

	};
};

#endif