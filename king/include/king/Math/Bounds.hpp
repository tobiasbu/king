
#ifndef   KING_BOUNDS_HPP
#define   KING_BOUNDS_HPP

#include <king/Entity/Renderer.hpp>
#include <king/Math/Vector2.hpp>
#include <king/Math/Vector3.hpp>
#include <king/Math/Rect.hpp>

namespace king {

	struct Bounds {

	private:

		Vector3f min;
		Vector3f max;
		Vector3f size;
		Rect rect;

	public:

		Bounds();
		Bounds(const Rect & rect);
		Bounds(const Vector3f & min, const Vector3f & max);
		Bounds(const Vector2f & min, const Vector2f & max);

		/// Getters

		Vector3f getMin();
		Vector3f getMax();
		Vector3f getSize();
		Rect getRect();
		Vector3f center();
		
		/// Functions

		bool intersects(const Bounds & bounds);
		bool contains(const Vector3f & point);
		bool contains(const Vector2f & point);

		void calculate(const Renderer * renderer);
		void calculate(const Vector2f & pos, const Vector2f & size, float depth);
		void calculate(const Vector2f & anchor, const Vector2f & pos, const Vector2f & scale, const Vector2f & size, float radians, float depth);
		void calculate(const Vector3f & anchor, const Vector3f & pos, const Vector3f & scale, const Vector3f & size, const Vector3f & radiansAxis, float depth);

		/// Static Functions

		static bool intersects(const Bounds & a, const Bounds & b);
		static bool contains(const Bounds & bounds, const Vector3f & point);
		static bool contains(const Bounds & bounds, const Vector2f & point);

	};

}

#endif