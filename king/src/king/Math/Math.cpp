
#include <king\Math\Math.hpp>

namespace king {

	//const double Math::PI = 3.14159265359;
	//const double Math::HALF_PI = Math::PI / 2;
	//const double Math::degToRad = 0.01745329251; // PI / 180
	//const double Math::radToDeg = 57.2957795131; // 180 / PI

		int Math::factorial(int n) {

		
			int result = 1.0;
			for (int i = 2; i <= n; i++)
				result *= i;

			return result;

		}

		double Math::power(double x, int y) {

			double p = 1.0;

			for (int i = 1; i <= y; i++)
				p = p*x;

			return p;

		}

		// not implemented yet
		double Math::cos(double x) {

			return 0;

		}

		// not implemented
		double Math::sin(double x) {

			return 0;

			/*double sum_pos = 0;
			double sum_neg = 0;
			double t_sum = 0;

			for (int i = 1; i <= 1000; i += 4)
			{
				sum_pos = sum_pos + (power(x, i) / fact(i));
			}

			for (int i = 3; i <= 1000; i += 4)
			{
				sum_neg = sum_neg + (power(x, i) / fact(i));
			}

			t_sum = sum_pos - sum_neg;

			return t_sum;*/

		}

		float Math::lerp(float from, float to, float t) {

			return (1 - t)*from + t*to;

		}


/*		Vector2f Math::lerp(Vector2f from, Vector2f to, float t) {

			return 1;//(1 - t)*from + t*to;

		}*/

		double Math::degreesToRadians(double degrees) {

			return degrees * Math::degToRad;

		}

		double Math::radiansToDegrees(double radians) {

			return Math::radToDeg * radians;

		}

		int32 Math::sign(float value) {
			return (value > 0) - (value < 0);
		}

		int32 Math::sign(int value) {
			return (value > 0) - (value < 0);
		}

		float Math::clamp(float value, float min, float max) {
			return (value > min) ? (value < max) ? value : max : min;
		}

		float Math::min(float value, float min) {
			return (value < min) ? min : value;
		}

		float Math::max(float value, float max) {
			return (value > max) ? max : value;
		}

		int Math::intClamp(int value, int min, int max) {
			return (value > min) ? (value < max) ? value : max : min;
		}

		int Math::intMin(int value, int min) {
			return (value < min) ? min : value;
		}

		int Math::intMax(int value, int max) {
			return (value > max) ? max : value;
		}



}