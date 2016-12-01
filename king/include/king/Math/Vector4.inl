
namespace king {

	namespace mathdetails {
		template <typename T>
		struct vec4_add
		{
			static Vector4<T> call(Vector4<T> const & a, Vector4<T> const & b)
			{
				return Vector4<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
			}
		};

		template <typename T>
		struct vec4_sub
		{
			static Vector4<T> call(Vector4<T> const & a, Vector4<T> const & b)
			{
				return Vector4<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
			}
		};

		template <typename T>
		struct vec4_mul
		{
			static Vector4<T> call(Vector4<T> const & a, Vector4<T> const & b)
			{
				return Vector4<T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
			}
		};

		template <typename T>
		struct vec4_div
		{
			static Vector4<T> call(Vector4<T> const & a, Vector4<T> const & b)
			{
				return Vector4<T>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
			}
		};
	}

	////////////////////////////////////////////////////////////
	// Constructors
	////////////////////////////////////////////////////////////

	template <typename T>
	Vector4<T>::Vector4()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	template <typename T>
	Vector4<T>::Vector4(Vector4<T> const & v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	template <typename T>
	Vector4<T>::Vector4(T const & a, T const & b, T const & c) :
		x(a),
		y(b),
		z(c),
		w(0)
	{

	}

	template <typename T>
	Vector4<T>::Vector4(T const & a, T const & b, T const & c, T const & d) :
		x(a),
		y(b),
		z(c),
		w(d)
	{

	}

	////////////////////////////////////////////////////////////
	// Explicit Conversion Constructors
	////////////////////////////////////////////////////////////

	template <typename T>
	template <typename U>
	Vector4<T>::Vector4(U const & scalar) :
		x(static_cast<T>(scalar)),
		y(static_cast<T>(scalar)),
		z(static_cast<T>(scalar)),
		w(static_cast<T>(scalar))
	{

	}

	template <typename T>
	template <typename U>
	Vector4<T>::Vector4(const Vector4<U>& v) :
		x(static_cast<T>(v.x)),
		y(static_cast<T>(v.y)),
		z(static_cast<T>(v.z)),
		w(static_cast<T>(v.w))
	{

	}

	template <typename T>
	template <typename U>
	Vector4<T>::Vector4(const Vector2<U>& v2) {
		this->x = static_cast<T>(v2.x);
		this->y = static_cast<T>(v2.y);
		this->z = 0;
		this->w = 0;
	}

	template <typename T>
	template <typename U>
	Vector4<T>::Vector4(const Vector3<U>& v3) {
		this->x = static_cast<T>(v3.x);
		this->y = static_cast<T>(v3.y);
		this->z = static_cast<T>(v3.z);
		this->w = 0;
	}

	////////////////////////////////////////////////////////////
	// Operators
	////////////////////////////////////////////////////////////

	// -- Relational Operators --

	template <typename T>
	bool Vector4<T>::operator<(const Vector4<T> other) const {

		return (this->x < other.x) && (this->y < other.y) && (this->z < other.z) && (this->w < other.w);

	}

	template <typename T>
	bool Vector4<T>::operator<=(const Vector4<T> other) const {

		return (this->x <= other.x) && (this->y <= other.y) && (this->z <= other.z) && (this->w <= other.w);

	}

	template <typename T>
	bool Vector4<T>::operator>(const Vector4<T> other) const {

		return (this->x > other.x) && (this->y > other.y) && (this->z > other.z) && (this->w > other.w);

	}

	template <typename T>
	bool Vector4<T>::operator>=(const Vector4<T> other) const {

		return (this->x >= other.x) && (this->y >= other.y) && (this->z >= other.z) && (this->w >= other.w);

	}

	// -- Unary Arithmetic Operators --

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator=(Vector4<U> const & v) {
		return Vector4<T>(v);
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator+=(U scalar) {
		return mathdetails::vec4_add<T>::call(*this, Vector4<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator+=(Vector4<U> const & v) {
		return mathdetails::vec4_add<T>::call(*this, Vector4<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator-=(U scalar) {
		return mathdetails::vec4_sub<T>::call(*this, Vector4<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator-=(Vector4<U> const & v) {
		return mathdetails::vec4_sub<T>::call(*this, Vector4<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator*=(U scalar) {
		return mathdetails::vec4_mul<T>::call(*this, Vector4<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator*=(Vector4<U> const& v) {
		return mathdetails::vec4_mul<T>::call(*this, Vector4<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator/=(U scalar) {
		return mathdetails::vec4_div<T>::call(*this, Vector4<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector4<T> & Vector4<T>::operator/=(Vector4<U> const & v) {
		return mathdetails::vec4_div<T>::call(*this, Vector4<T>(v));
	}

	// -- Booleans Operators --

	template<typename T>
	bool operator ==(const Vector4<T>& left, const Vector4<T>& right) {

		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);

	}

	template<typename T>
	bool operator !=(const Vector4<T>& left, const Vector4<T>& right) {

		return (left.x != right.x) || (left.y != right.y) || (left.z != right.z) || (left.w != right.w);

	}


	// -- Unary operators --

	template <typename T>
	Vector4<T> operator+(Vector4<T> const & v) {
		return v;
	}

	template <typename T>
	Vector4<T> operator-(Vector4<T> const & v) {
		return Vector4<T>(0) -= v;
	}

	// -- Binary Arithmetic Operators -- 

	// +

	template <typename T>
	Vector4<T> operator+(Vector4<T> const & v, T scalar)
	{
		return Vector4<T>(v) += scalar;
	}


	template <typename T>
	Vector4<T> operator+(T scalar, Vector4<T> const & v) {

		return Vector4<T>(v) += scalar;

	}

	template <typename T>
	Vector4<T> operator+(Vector4<T> const & v1, Vector4<T> const & v2) {

		return Vector4<T>(v1) += v2;

	}

	// -

	template <typename T>
	Vector4<T> operator-(Vector4<T> const & v, T scalar) {

		return Vector4<T>(v) -= scalar;

	}

	template <typename T>
	Vector4<T> operator-(T scalar, Vector4<T> const & v) {

		return Vector4<T>(scalar) -= v;

	}

	template <typename T>
	Vector4<T> operator-(Vector4<T> const & v1, Vector4<T> const & v2) {

		return Vector4<T>(v1) -= v2;
	}

	// *

	template <typename T>
	Vector4<T> operator*(Vector4<T> const & v, T scalar) {

		return Vector4<T>(v) *= scalar;

	}

	template <typename T>
	Vector4<T> operator*(T scalar, Vector4<T> const & v) {

		return Vector4<T>(v) *= scalar;

	}

	template <typename T>
	Vector4<T> operator*(Vector4<T> const & v1, Vector4<T> const & v2) {

		return Vector4<T>(v1) *= v2;

	}

	// /

	template <typename T>
	Vector4<T> operator/(Vector4<T> const & v, T scalar) {

		return Vector4<T>(v1) /= scalar;

	}

	template <typename T>
	Vector4<T> operator/(T scalar, Vector4<T> const & v) {

		return Vector4<T>(scalar) /= v;

	}

	template <typename T>
	Vector4<T> operator/(Vector4<T> const & v1, Vector4<T> const & v2) {

		return Vector4<T>(v1) /= v2;

	}

}