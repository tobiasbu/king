
#include <king/Math/Bounds.hpp>

namespace king {

	Bounds::Bounds() :
		min(Vector3f()),
		max(Vector3f()),
		size(Vector3f()),
		rect(Rect())
	{

	}

	Bounds::Bounds(const Rect & rect) :
		min(rect.position),
		max(rect.position + rect.size),
		size(rect.size),
		rect(rect)
	{

	}

	Bounds::Bounds(const Vector3f & min, const Vector3f & max) : 
		min(min),
		max(max),
		size(max - min),
		rect(min, max - min)
	{

	}

	Bounds::Bounds(const Vector2f & min, const Vector2f & max) : 
		min(min),
		max(max),
		size(max - min),
		rect(min, max - min)
	{

	}

	/// Getters

	Vector3f Bounds::getMin() {

		return min;

	}

	Vector3f Bounds::getMax() {

		return max;

	}

	Vector3f Bounds::getSize() {

		return size;

	}

	Rect Bounds::getRect() {

		return rect;

	}

	Vector3f Bounds::center() {

		return (max + min) / 2.0f;

	}

	/// Functions

	bool Bounds::intersects(const Bounds & bounds) {

		return Bounds::intersects(*this, bounds);

	}

	bool Bounds::contains(const Vector3f & point) {

		return Bounds::contains(*this, point);

	}

	bool Bounds::contains(const Vector2f & point) {

		return Bounds::contains(*this, point);

	}

	void Bounds::calculate(const Renderer * renderer) {


	}

	void Bounds::calculate(const Vector2f & anchor, const Vector2f & pos, const Vector2f & scale, const Vector2f & size, float angle, float depth) {


	}

	/// Static Functions

	bool Bounds::intersects(const Bounds & a, const Bounds & b) {

		return true;

	}

	bool Bounds::contains(const Bounds & bounds, const Vector3f & point) {

		return true;

	}

	bool Bounds::contains(const Bounds & bounds, const Vector2f & point) {

		return true;

	}


}