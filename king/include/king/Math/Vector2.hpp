


#ifndef KING_VECTOR2_HPP
#define KING_VECTOR2_HPP

#include <king/Math/VectorType.hpp>

#include <sstream>
#include <assert.h>

namespace king {

	template<typename T>
	class Vector2 {

	public:

		// Member Data
		T x; T y;
	
		// Constructors

		Vector2();
		Vector2(Vector2<T> const & v);
		Vector2(T const & a, T const & b);
		
		// Conversion Constructors

		template<typename U>
		explicit Vector2(const Vector2<U>& v);

		template<typename U>
		Vector2(U const & scalar);

		template<typename U>
		explicit Vector2(const Vector3<U>& v3);

		template<typename U>
		explicit Vector2(const Vector4<U>& v4);

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

		/// Operators

		// -- Relational Operators --

		bool operator<(const Vector2<T> other) const;

		bool operator<=(const Vector2<T> other) const;

		bool operator>(const Vector2<T> other) const;

		bool operator>=(const Vector2<T> other) const;

		// -- Unary arithmetic operators --

		inline Vector2<T> operator =(const Vector2<T> & other) {

			this->x = other.x;
			this->y = other.y;
			return *this;
			//return Vector3<T>(other.x, other.y, other.z);
		}

		template <typename U>
		 Vector2<T> & operator=(Vector2<U> const & v);

		template <typename U>
		 Vector2<T> & operator+=(U scalar);

		template <typename U>
		 Vector2<T> & operator+=(Vector2<U> const & v);

		template <typename U>
		 Vector2<T> & operator-=(U scalar);

		template <typename U>
		 Vector2<T> & operator-=(Vector2<U> const & v);

		template <typename U>
		 Vector2<T> & operator*=(U scalar);

		template <typename U>
		 Vector2<T> & operator*=(Vector2<U> const& v);

		template <typename U>
		 Vector2<T> & operator/=(U scalar);

		template <typename U>
		 Vector2<T> & operator/=(Vector2<U> const & v);

		 // Array Subscriptor

		 T & operator[](const size_t index) {

			assert(index >= 0 && index < 2 && "KING::Vector2 Can not access Vector2 element.");

			return (&x)[index];

		}

		 const T & operator[](const size_t index) const {

			assert(index >= 0 && index < 2 && "KING::Vector2 Can not access Vector2 element.");

			return (&x)[index];

		}
	};

	// -- Boolean operators --

	template <typename T>
	bool operator==(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	bool operator!=(Vector2<T> const & v1, Vector2<T> const & v2);

	// -- Unary operators --

	template <typename T>
	 Vector2<T> operator+(Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator-(Vector2<T> const & v);

	// -- Binary operators --

	template <typename T>
	 Vector2<T> operator+(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator+(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator+(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator-(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator-(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator-(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator*(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator*(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator*(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator/(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator/(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator/(Vector2<T> const & v1, Vector2<T> const & v2);

	/*template <typename T>
	 Vector2<T> operator%(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator%(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator%(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator&(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator&(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator&(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator|(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator|(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator|(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator^(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator^(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator^(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator<<(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator<<(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator<<(Vector2<T> const & v1, Vector2<T> const & v2);

	template <typename T>
	 Vector2<T> operator>>(Vector2<T> const & v, T scalar);

	template <typename T>
	 Vector2<T> operator>>(T scalar, Vector2<T> const & v);

	template <typename T>
	 Vector2<T> operator>>(Vector2<T> const & v1, Vector2<T> const & v2);
	 
	template <typename T>
	Vector2<T> operator~(Vector2<T> const & v);*/

	
}

#include "Vector2.inl"

#endif