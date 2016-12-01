




#ifndef KING_VECTOR4_HPP
#define KING_VECTOR4_HPP

#include <king/Math/VectorType.hpp>

#include <sstream>
#include <assert.h>

namespace king {

	template<typename T>
	class Vector4 {

	public:

		//typedef value_type T;

		T x, y, z, w;
		/*union { T x; T r;  T s; };
		union { T y; T g;  T t; };
		union { T z; T b;  T p; };
		union { T w; T a;  T d; };*/

		// Constructors

		Vector4();
		Vector4(Vector4<T> const & v);
		Vector4(T const & a, T const & b, T const & c);
		Vector4(T const & a, T const & b, T const & c, T const & d);

		// Conversion Constructors

		template<typename U>
		explicit Vector4(const Vector4<U>& v);

		template<typename U>
		Vector4(U const & scalar);

		template<typename U>
		explicit Vector4(const Vector2<U>& v2);

		template<typename U>
		explicit Vector4(const Vector3<U>& v3);

		// Functions

		Vector4<T> & zero() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->w = 0;
			return *this;
		}

		void set(T x) {

			this->x = x;
			this->y = x;
			this->z = x;
			this->w = x;
		}

		void set(T x, T y, T z, T w) {

			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;

		}

		Vector4<T> & add(T scalar) {

			this->x += scalar;
			this->y += scalar;
			this->z += scalar;
			this->w += scalar;
			return *this;

		}
		
		Vector4<T> & sub(T scalar) {
			this->x -= scalar;
			this->y -= scalar;
			this->z -= scalar;
			this->w -= scalar;
			return *this;
		}
		
		Vector4<T> & mult(T scalar) {
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;
			return *this;
		}
		
		Vector4<T> & div(T scalar) {
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			this->w /= scalar;
			return *this;
		}

		std::string toString() {

			std::stringstream str;
			str << x << ", " << y << ", " << z << ", " << w;
			return str.str();
		}

		/*static float distance(Vector4f, Vector4f);
		static Vector4f midPoint(Vector4f, Vector4f);
		static Vector4f crossProduct(Vector4f, Vector4f);
		static float dot(Vector4f, Vector4f);
		float normal();*/

		// Operators

		// -- Relational Operators --

		bool operator<(const Vector4<T> other) const;

		bool operator<=(const Vector4<T> other) const;

		bool operator>(const Vector4<T> other) const;

		bool operator>=(const Vector4<T> other) const;

		// -- Unary arithmetic operators --
	
		inline Vector4<T> operator =(const Vector4<T> & other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
			return *this; 
			//return Vector4<T>(other.x, other.y, other.z);
		}
		
		template <typename U>
		Vector4<T> & operator=(Vector4<U> const & v);

		template <typename U>
		Vector4<T> & operator+=(U scalar);

		template <typename U>
		Vector4<T> & operator+=(Vector4<U> const & v);

		template <typename U>
		Vector4<T> & operator-=(U scalar);

		template <typename U>
		Vector4<T> & operator-=(Vector4<U> const & v);

		template <typename U>
		Vector4<T> & operator*=(U scalar);

		template <typename U>
		Vector4<T> & operator*=(Vector4<U> const& v);

		template <typename U>
		Vector4<T> & operator/=(U scalar);

		template <typename U>
		Vector4<T> & operator/=(Vector4<U> const & v);

		// Array Subscriptor

		T & operator[](const size_t index) {

			assert(index >= 0 && index < 4 && "KING::Vector4 Can not access Vector4 element.");

			return (&x)[index];

		}

		const T & operator[](const size_t index) const {

			assert(index >= 0 && index < 4 && "KING::Vector4 Can not access Vector4 element.");

			return (&x)[index];

		}

		
	};


	// -- Boolean operators --

	template<typename T>
	bool operator ==(const Vector4<T>& left, const Vector4<T>& right);

	template<typename T>
	bool operator !=(const Vector4<T>& left, const Vector4<T>& right);

	// -- Unary operators --

	template <typename T>
	Vector4<T> operator+(Vector4<T> const & v);

	template <typename T>
	Vector4<T> operator-(Vector4<T> const & v);

	// -- Binary operators --

	template <typename T>
	Vector4<T> operator+(Vector4<T> const & v, T scalar);

	template <typename T>
	Vector4<T> operator+(T scalar, Vector4<T> const & v);

	template <typename T>
	Vector4<T> operator+(Vector4<T> const & v1, Vector4<T> const & v2);

	template <typename T>
	Vector4<T> operator-(Vector4<T> const & v, T scalar);

	template <typename T>
	Vector4<T> operator-(T scalar, Vector4<T> const & v);

	template <typename T>
	Vector4<T> operator-(Vector4<T> const & v1, Vector4<T> const & v2);

	template <typename T>
	Vector4<T> operator*(Vector4<T> const & v, T scalar);

	template <typename T>
	Vector4<T> operator*(T scalar, Vector4<T> const & v);

	template <typename T>
	Vector4<T> operator*(Vector4<T> const & v1, Vector4<T> const & v2);

	template <typename T>
	Vector4<T> operator/(Vector4<T> const & v, T scalar);

	template <typename T>
	Vector4<T> operator/(T scalar, Vector4<T> const & v);

	template <typename T>
	Vector4<T> operator/(Vector4<T> const & v1, Vector4<T> const & v2);

}

#include "Vector4.inl"

#endif

