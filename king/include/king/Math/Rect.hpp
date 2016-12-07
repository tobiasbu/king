
#ifndef   KING_RECT_HPP
#define   KING_RECT_HPP

#include <king/Math/Vector2.hpp>

namespace king {

	struct Rect {

	public:
		/// Member Data
		union {
			struct {
				Vector2f position;
			};
			float x, y;			
		};
		
		union {
			struct {
				Vector2f size;
			};
			float width, height;
		};

		/// Contructors

		Rect();
		Rect(const Rect &);
		Rect(const Vector2f &, const Vector2f &);
		Rect(float, float, float, float);

		/// Functions

		bool intersects(const Rect & other);
		bool contains(const Vector2f & point);
		Vector2f center();

		/// Static Functions

		static bool intersects(const Rect & A, const Rect & B);
		static bool contains(const Rect & rect, const Vector2f & point);
		static Vector2f center(const Rect & rect);

		/// Operators

	};

}

#endif