
#ifndef KING_VECTOR2_H
#define KING_VECTOR2_H

#include <sstream>
#include <assert.h>

namespace king {

	template<typename T>
	class Vector2 {

	public:

		// Data
		T x;
		T y;

		// Constructors

		Vector2();
		Vector2(T const & a, T const & b);

		template<typename U>
		explicit Vector2(const Vector2<U>& vector);

		template<typename U>
		Vector2(U const & scalar);

		// Functions

		Vector2<T> & zero() {
			this->x = 0;
			this->y = 0;
			return *this;
		}

		void set(T x) {

			this->x = x;
			this->y = x;
		}

		void set(T x, T y) {

			this->x = x;
			this->y = y;

		}

		Vector2<T> & add(T scalar) {

			this->x += scalar;
			this->y += scalar;
			return *this;

		}
		Vector2<T> & sub(T scalar) {
			this->x -= scalar;
			this->y -= scalar;
			return *this;
		}
		Vector2<T> & mult(T scalar) {
			this->x *= scalar;
			this->y *= scalar;
			return *this;
		}
		Vector2<T> & div(T scalar) {
			this->x /= scalar;
			this->y /= scalar;
			return *this;
		}

		std::string toString() {

			std::stringstream str;
			str << x << ", " << y;
			return str.str();
		}

		// Operators
		// -- Unary arithmetic operators --

		inline Vector2<T> operator =(const Vector2<T> & other) {

			this->x = other.x;
			this->y = other.y;
			return *this;
			//return Vector3<T>(other.x, other.y, other.z);
		}

		T & operator[](const size_t index) {


			assert(index >= 0 && index < 2 && "KING::Vector2 Can not access Vector2 element.");

			switch (index) {
			case 0: return x; break;
			case 1: return y; break;
			}



		}
		const T & operator[](const size_t index) const {

			assert(index >= 0 && index < 2 && "KING::Vector3 Can not access Vector2 element.");

			switch (index) {
			case 0: return x; break;
			case 1: return y; break;
			}

		}
	};

#include "Vector2.inl"

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2ui;
}



#endif