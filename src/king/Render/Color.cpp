
#include <king\Render\Color.hpp>
#include <king\Math\Math.hpp>
#include <sstream>

namespace king {

	const Color Color::white(1, 1, 1, 1);
	const Color Color::grey(0.5f, 0.5f, 0.5f, 1);
	const Color Color::black(0, 0, 0, 1);
	const Color Color::transparent(0, 0, 0, 0);
	const Color Color::red(1, 0, 0, 1);
	const Color Color::green(0, 1, 0, 1);
	const Color Color::blue(0, 0, 1, 1);
	const Color Color::yellow(1, 1, 0, 1);
	const Color Color::cyan(0, 1, 1, 1);
	const Color Color::magenta(1, 0, 1, 1);

	Color::Color() :
		r(1.0),
		g(1.0),
		b(1.0),
		a(1.0) 
	{
	}

	Color::Color(float R, float G, float B, float A = 1) :
		r(R),
		g(G),
		b(B),
		a(A)
	{
	/*	this->r = (float)r;
		this->g = (float)g;
		this->b = (float)b;
		this->a = (float)a;*/

		//return this;
	}

	void Color::setRGB(int r, int g, int b, int a = 255) {

		this->r = (float)r / 255.0f;
		this->g = (float)g / 255.0f;
		this->b = (float)b / 255.0f;
		this->a = (float)a / 255.0f;

	}

	std::string Color::toString() {

		std::stringstream str;
		str << r << ", " << g << ", " << b << ", " << a;
		return str.str();

	}

	Color Color::makeFromRGBColor(int r, int g, int b, int a = 255) {

		Color color;
		color.r = (float)r / 255.0f;
		color.g = (float)g / 255.0f;
		color.b = (float)b / 255.0f;
		color.a = (float)a / 255.0f;

		return color;

	}

	Color Color::lerp(Color from, Color to, float t) {

		Color l;
		l.r = Math::lerp(from.r, to.r, t);
		l.g = Math::lerp(from.g, to.g, t);
		l.b = Math::lerp(from.b, to.b, t);
		l.a = Math::lerp(from.a, to.a, t);

		return l;

	}

	bool Color::operator==(Color other) const
	{
		if (other.r == r && other.g == g &&	other.b == b &&	other.a == a)
			return true;
		else
			return false;
	}

}

