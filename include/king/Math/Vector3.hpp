




#ifndef KING_VECTOR3_H
#define KING_VECTOR3_H

#include <sstream>
#include <assert.h>

namespace king {

	template<typename T>
	class Vector3 {

	public:

		//typedef value_type T;


		union { T x; T r;  T s; };
		union { T y; T g;  T t; };
		union { T z; T b;  T p; };

		// Constructors

		Vector3();
		Vector3(T const & a, T const & b);
		Vector3(T const & a, T const & b, T const & c);

		template<typename U>
		explicit Vector3(const Vector3<U>& vector);

		template<typename U>
		Vector3(U const & scalar);

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

		// Static functions

		
	


		// Operators
		// -- Unary arithmetic operators --
	
		inline Vector3<T> operator =(const Vector3<T> & other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this; 
			//return Vector3<T>(other.x, other.y, other.z);
		}
		
		T & operator[](const size_t index) {

		
			assert(index >= 0 && index < 3 && "KING::Vector3 Can not access Vector3 element.");

			switch (index) {
			case 0: return x; break;
			case 1: return y; break;
			case 2: return z; break;
			}
			
			

		}

		const T & operator[](const size_t index) const {

			assert(index >= 0 && index < 3 && "KING::Vector3 Can not access Vector3 element.");

			switch (index) {
			case 0: return x; break;
			case 1: return y; break;
			case 2: return z; break;
			}

		}

		
	};


	

	template<typename T>
	bool operator ==(const Vector3<T>& left, const Vector3<T>& right);

	template<typename T>
	bool operator !=(const Vector3<T>& left, const Vector3<T>& right);


	////////////////////////////////////////////////////////////
	/// \relates Vector3
	/// \brief Unary operator +
	///
	/// \param self Vector to positive
	///
	/// \return Memberwise opposite of the vector
	///
	////////////////////////////////////////////////////////////
	template<typename T>
	Vector3<T> operator +(const Vector3<T>& self, const Vector3<T>& other);

	////////////////////////////////////////////////////////////
	/// \relates Vector3
	/// \brief Binary operator +=
	///
	/// This operator performs a memberwise addition of both vectors,
	/// and assigns the result to \a left.
	///
	/// \param self  Left operand (a vector)
	/// \param other Right operand (a vector)
	///
	/// \return Reference to \a self
	///
	////////////////////////////////////////////////////////////
	template<typename T>
	Vector3<T>& operator +=(Vector3<T>& self, const Vector3<T>& other);

	////////////////////////////////////////////////////////////
	/// \relates Vector3
	/// \brief Unary operator -
	///
	/// \param self Vector to negate
	///
	/// \return Memberwise opposite of the vector
	///
	////////////////////////////////////////////////////////////
	template<typename T>
	Vector3<T> operator -(const Vector3<T>& self, const Vector3<T>& other);

	////////////////////////////////////////////////////////////
	/// \relates Vector3
	/// \brief Binary operator -=
	///
	/// This operator performs a memberwise addition of both vectors,
	/// and assigns the result to \a left.
	///
	/// \param self  Left operand (a vector)
	/// \param other Right operand (a vector)
	///
	/// \return Reference to \a self
	///
	////////////////////////////////////////////////////////////
	template<typename T>
	Vector3<T>& operator -=(Vector3<T>& self, const Vector3<T>& other);

	template<typename T>
	Vector3<T>& operator *=(Vector3<T>& left, T right);

	template<typename T>
	Vector3<T>& operator *(const Vector3<T>& self, T right);

	template<typename T>
	Vector3<T>& operator *(T left, const Vector3<T>& right);

	template<typename T>
	Vector3<T>& operator /=(Vector3<T>& left, T right);

	template<typename T>
	Vector3<T> operator /(const Vector3<T>& left, T right);

	/// Negate
	template <typename T>
	Vector3<T> operator -(const Vector3<T>& self);



	////////////////////////////////////////////////////////////
	/// Overloaded Scalar Operators (not do that)
	////////////////////////////////////////////////////////////
	//template<typename T>
	//Vector3<T>& operator -=(Vector3<T>& self, const T & value);
	//template<typename T>
	//Vector3<T>& operator +=(Vector3<T>& self, const T & value);
	//template<typename T>
	//Vector3<T> operator +(const Vector3<T>& self, const T&  value);

	
#include "Vector3.inl"




	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;

	
	

}

#endif

