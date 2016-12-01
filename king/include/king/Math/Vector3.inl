

//#include "Vector3.hpp"

namespace king {

	namespace mathdetails {
		template <typename T>
		struct vec3_add
		{
			static Vector3<T> call(Vector3<T> const & a, Vector3<T> const & b)
			{
				return Vector3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
			}
		};

		template <typename T>
		struct vec3_sub
		{
			static Vector3<T> call(Vector3<T> const & a, Vector3<T> const & b)
			{
				return Vector3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
			}
		};

		template <typename T>
		struct vec3_mul
		{
			static Vector3<T> call(Vector3<T> const & a, Vector3<T> const & b)
			{
				return Vector3<T>(a.x * b.x, a.y * b.y, a.z * b.z);
			}
		};

		template <typename T>
		struct vec3_div
		{
			static Vector3<T> call(Vector3<T> const & a, Vector3<T> const & b)
			{
				return Vector3<T>(a.x / b.x, a.y / b.y, a.z / b.z);
			}
		};
	}

	////////////////////////////////////////////////////////////
	// Constructors
	////////////////////////////////////////////////////////////

	template <typename T>
	Vector3<T>::Vector3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	template <typename T>
	Vector3<T>::Vector3(Vector3<T> const & v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	template <typename T>
	Vector3<T>::Vector3(T const & a, T const & b) :
		x(a),
		y(b),
		z(0)
	{

	}

	template <typename T>
	Vector3<T>::Vector3(T const & a, T const & b, T const & c) :
		x(a),
		y(b),
		z(c)
	{

	}

	////////////////////////////////////////////////////////////
	// Explicit Conversion Constructors
	////////////////////////////////////////////////////////////

	template <typename T>
	template <typename U>
	Vector3<T>::Vector3(U const & scalar) :
		x(static_cast<T>(scalar)),
		y(static_cast<T>(scalar)),
		z(static_cast<T>(scalar))
	{

	}

	template <typename T>
	template <typename U>
	Vector3<T>::Vector3(const Vector3<U>& v) :
		x(static_cast<T>(v.x)),
		y(static_cast<T>(v.y)),
		z(static_cast<T>(v.z))
	{
	}

	template <typename T>
	template <typename U>
	Vector3<T>::Vector3(const Vector2<U>& v2) {
		this->x = static_cast<T>(v2.x);
		this->y = static_cast<T>(v2.y);
		this->z = 0;
	}

	template <typename T>
	template <typename U>
	Vector3<T>::Vector3(const Vector4<U>& v4) {
		this->x = static_cast<T>(v4.x);
		this->y = static_cast<T>(v4.y);
		this->z = static_cast<T>(v4.z);
	}

	////////////////////////////////////////////////////////////
	// Operators
	////////////////////////////////////////////////////////////

	// -- Relational Operators --

	template <typename T>
	bool Vector3<T>::operator<(const Vector3<T> other) const {

		return (this->x < other.x) && (this->y < other.y) && (this->z < other.z);

	}

	template <typename T>
	bool Vector3<T>::operator<=(const Vector3<T> other) const {

		return (this->x <= other.x) && (this->y <= other.y) && (this->z <= other.z);

	}

	template <typename T>
	bool Vector3<T>::operator>(const Vector3<T> other) const {

		return (this->x > other.x) && (this->y > other.y) && (this->z > other.z);

	}

	template <typename T>
	bool Vector3<T>::operator>=(const Vector3<T> other) const {

		return (this->x >= other.x) && (this->y >= other.y) && (this->z >= other.z);

	}

	// -- Unary Arithmetic Operators --

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator=(Vector3<U> const & v) {
		return Vector3<T>(v);
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator+=(U scalar) {
		return mathdetails::vec3_add<T>::call(*this, Vector3<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator+=(Vector3<U> const & v) {
		return mathdetails::vec3_add<T>::call(*this, Vector3<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator-=(U scalar) {
		return mathdetails::vec3_sub<T>::call(*this, Vector3<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator-=(Vector3<U> const & v) {
		return mathdetails::vec3_sub<T>::call(*this, Vector3<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator*=(U scalar) {
		return mathdetails::vec3_mul<T>::call(*this, Vector3<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator*=(Vector3<U> const& v) {
		return mathdetails::vec3_mul<T>::call(*this, Vector3<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator/=(U scalar) {
		return mathdetails::vec3_div<T>::call(*this, Vector3<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector3<T> & Vector3<T>::operator/=(Vector3<U> const & v) {
		return mathdetails::vec3_div<T>::call(*this, Vector3<T>(v));
	}

	// -- Booleans Operators --

	template<typename T>
	inline bool operator ==(const Vector3<T>& left, const Vector3<T>& right) {

		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);

	}

	template<typename T>
	inline bool operator !=(const Vector3<T>& left, const Vector3<T>& right) {

		return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);

	}

	// -- Unary operators --

	template <typename T>
	Vector3<T> operator+(Vector3<T> const & v) {
		return v;
	}

	template <typename T>
	Vector3<T> operator-(Vector3<T> const & v) {
		return Vector3<T>(0) -= v;
	}

	// Binary Arithmetic Operators

	// +

	template <typename T>
	Vector3<T> operator+(Vector3<T> const & v, T scalar)
	{
		return Vector3<T>(v) += scalar;
	}


	template <typename T>
	Vector3<T> operator+(T scalar, Vector3<T> const & v) {

		return Vector3<T>(v) += scalar;

	}

	template <typename T>
	Vector3<T> operator+(Vector3<T> const & v1, Vector3<T> const & v2) {

		return Vector3<T>(v1) += v2;

	}

	// -

	template <typename T>
	Vector3<T> operator-(Vector3<T> const & v, T scalar) {

		return Vector3<T>(v) -= scalar;

	}

	template <typename T>
	Vector3<T> operator-(T scalar, Vector3<T> const & v) {

		return Vector3<T>(scalar) -= v;

	}

	template <typename T>
	Vector3<T> operator-(Vector3<T> const & v1, Vector3<T> const & v2) {

		return Vector3<T>(v1) -= v2;
	}

	// *

	template <typename T>
	Vector3<T> operator*(Vector3<T> const & v, T scalar) {

		return Vector3<T>(v) *= scalar;

	}

	template <typename T>
	Vector3<T> operator*(T scalar, Vector3<T> const & v) {

		return Vector3<T>(v) *= scalar;

	}

	template <typename T>
	Vector3<T> operator*(Vector3<T> const & v1, Vector3<T> const & v2) {

		return Vector3<T>(v1) *= v2;

	}

	// /

	template <typename T>
	Vector3<T> operator/(Vector3<T> const & v, T scalar) {

		return Vector3<T>(v1) /= scalar;

	}

	template <typename T>
	Vector3<T> operator/(T scalar, Vector3<T> const & v) {

		return Vector3<T>(scalar) /= v;

	}

	template <typename T>
	Vector3<T> operator/(Vector3<T> const & v1, Vector3<T> const & v2) {

		return Vector3<T>(v1) /= v2;

	}

}