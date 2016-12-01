
#ifndef KING_MATH_HPP
#define KING_MATH_HPP

#include <king\Math\Vector2.hpp>
#include <king\KingTypes.hpp>

namespace king {

	namespace Math {

		static const double PI = 3.14159265359;
		static const double HALF_PI = PI / 2 ; // PI / 2
		static const double degToRad = 0.01745329251;
		static const double radToDeg = 57.2957795131;

		int factorial(int n);
		double sin(double x);
		double cos(double x);
		double power(double x, int y);

		float lerp(float from, float to, float t);
		//Vector2f lerp(Vector2f from, Vector2f to, float t);
		double degreesToRadians(double);
		double radiansToDegrees(double);

		int32 sign(float value);
		int32 sign(int value);
		
		float clamp(float value, float min, float max);
		float min(float value, float min);
		float max(float value, float max);

		int intClamp(int value, int min, int max);
		int intMin(int value, int min);
		int intMax(int value, int max);

	}
};

#endif