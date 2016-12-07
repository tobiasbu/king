
#include <king/Math/Rect.hpp>

namespace king {

	Rect::Rect() :
		position(Vector2f()),
		size(Vector2f())
	{

	}

	Rect::Rect(const Rect & rect) :
		position(rect.position),
		size(rect.size)
	{

	}

	Rect::Rect(const Vector2f & position, const Vector2f & size) :
		position(position),
		size(size)
	{

	}

	Rect::Rect(float x, float y, float width, float height) :
		x(x),
		y(y),
		width(width),
		height(height) 
	{

	}

	bool Rect::intersects(const Rect & other) {

		return Rect::intersects(*this, other);
	}

	bool Rect::contains(const Vector2f & point) {

		return Rect::contains(*this, point);

	}

	bool Rect::intersects(const Rect & a, const Rect & b) {

		if (a.width <= 0 || a.height <= 0 || b.width <= 0 || b.height <= 0)
			return false;

		return  !(a.x > b.x + b.width ||
			a.x + a.width < b.x ||
			a.y > b.y + b.height ||
			a.y + a.height < b.y);

	}

	bool Rect::contains(const Rect & rect, const Vector2f & point) {
		
		if (rect.width <= 0 && rect.height <= 0)
			return false;

		return (point.x > rect.x &&
			point.x < rect.x + rect.width &&
			point.y >= rect.y &&
			point.y < rect.y + rect.height);
	}

	Vector2f Rect::center() {

		return Rect::center(*this);

	}

	Vector2f Rect::center(const Rect & rect) {

		return Vector2f(rect.x + rect.width / 2, rect.y + rect.height / 2);

	}

}