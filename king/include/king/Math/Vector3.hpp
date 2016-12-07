




#ifndef KING_VECTOR3_HPP
#define KING_VECTOR3_HPP

#include <king/Math/VectorType.hpp>

#include <sstream>
#include <assert.h>

namespace king {

	template<typename T>
	class Vector3 {

	public:

		
		// Member Data
		T x, y, z;

		/*union { T x; T r;  T s; };
		union { T y; T g;  T t; };
		union { T z; T b;  T p; };*/

		// Constructors

		Vector3();
		Vector3(Vector3<T> const & v);
		Vector3(T const & a);
		Vector3(T const & a, T const & b);
		Vector3(T const & a, T const & b, T const & c);

		// Conversion Constructors

		template<typename U>
		explicit Vector3(const Vector3<U>& v);

		template<typename U>
		Vector3(U const & scalar);

		template<typename U>
		explicit Vector3(const Vector2<U>& v2);

		template<typename U>
		explicit Vector3(const Vector4<U>& v4);

		// Functions

		Vector3<T> & zero() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
			return *this;
		}

		void set(T x) {

			this->x = x;
			this->y = x;
			this->z = x;
		}

		void set(T x, T y, T z) {

			this->x = x;
			this->y = y;
			this->z = z;

		}

		Vector3<T> & add(T scalar) {

			this->x += scalar;
			this->y += scalar;
			this->z += scalar;
			return *this;

		}
		
		Vector3<T> & sub(T scalar) {
			this->x -= scalar;
			this->y -= scalar;
			this->z -= scalar;
			return *this;
		}
		
		Vector3<T> & mult(T scalar) {
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			return *this;
		}
		
		Vector3<T> & div(T scalar) {
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			return *this;
		}

		std::string toString() {

			std::stringstream str;
			str << x << ", " << y << ", " << z;
			return str.str();
		}

		/*static float distance(Vector3f, Vector3f);
		static Vector3f midPoint(Vector3f, Vector3f);
		static Vector3f crossProduct(Vector3f, Vector3f);
		static float dot(Vector3f, Vector3f);
		float normal();*/

		// Operators

		// Relational Operators

		bool operator<(const Vector3<T> other) const;

		bool operator<=(const Vector3<T> other) const;

		bool operator>(const Vector3<T> other) const;

		bool operator>=(const Vector3<T> other) const;

		// -- Unary arithmetic operators --
	
		inline Vector3<T> operator =(const Vector3<T> & other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this; 
			//return Vector3<T>(other.x, other.y, other.z);
		}
		
		template <typename U>
		Vector3<T> & operator=(Vector3<U> const & v);

		template <typename U>
		Vector3<T> & operator+=(U scalar);

		template <typename U>
		Vector3<T> & operator+=(Vector3<U> const & v);

		template <typename U>
		Vector3<T> & operator-=(U scalar);

		template <typename U>
		Vector3<T> & operator-=(Vector3<U> const & v);

		template <typename U>
		Vector3<T> & operator*=(U scalar);

		template <typename U>
		Vector3<T> & operator*=(Vector3<U> const& v);

		template <typename U>
		Vector3<T> & operator/=(U scalar);

		template <typename U>
		Vector3<T> & operator/=(Vector3<U> const & v);

		// Array Subscriptor

		T & operator[](const size_t index) {

			assert(index >= 0 && index < 3 && "KING::Vector3 Can not access Vector3 element.");

			return (&x)[index];

		}

		const T & operator[](const size_t index) const {

			assert(index >= 0 && index < 3 && "KING::Vector3 Can not access Vector3 element.");

			return (&x)[index];

		}

		
	};

	// -- Boolean operators --	

	template<typename T>
	bool operator ==(const Vector3<T>& left, const Vector3<T>& right);

	template<typename T>
	bool operator !=(const Vector3<T>& left, const Vector3<T>& right);

	// -- Unary operators --

	template <typename T>
	Vector3<T> operator+(Vector3<T> const & v);

	template <typename T>
	Vector3<T> operator-(Vector3<T> const & v);

	// -- Binary operators --

	template <typename T>
	Vector3<T> operator+(Vector3<T> const & v, T scalar);

	template <typename T>
	Vector3<T> operator+(T scalar, Vector3<T> const & v);

	template <typename T>
	Vector3<T> operator+(Vector3<T> const & v1, Vector3<T> const & v2);

	template <typename T>
	Vector3<T> operator-(Vector3<T> const & v, T scalar);

	template <typename T>
	Vector3<T> operator-(T scalar, Vector3<T> const & v);

	template <typename T>
	Vector3<T> operator-(Vector3<T> const & v1, Vector3<T> const & v2);

	template <typename T>
	Vector3<T> operator*(Vector3<T> const & v, T scalar);

	template <typename T>
	Vector3<T> operator*(T scalar, Vector3<T> const & v);

	template <typename T>
	Vector3<T> operator*(Vector3<T> const & v1, Vector3<T> const & v2);

	template <typename T>
	Vector3<T> operator/(Vector3<T> const & v, T scalar);

	template <typename T>
	Vector3<T> operator/(T scalar, Vector3<T> const & v);

	template <typename T>
	Vector3<T> operator/(Vector3<T> const & v1, Vector3<T> const & v2);
	


}

#include "Vector3.inl"

#endif

