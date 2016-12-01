
namespace king {

	namespace mathdetails {
		template <typename T>
		struct vec2_add
		{
			static Vector2<T> call(Vector2<T> const & a, Vector2<T> const & b)
			{
				return Vector2<T>(a.x + b.x, a.y + b.y);
			}
		};

		template <typename T>
		struct vec2_sub
		{
			static Vector2<T> call(Vector2<T> const & a, Vector2<T> const & b)
			{
				return Vector2<T>(a.x - b.x, a.y - b.y);
			}
		};

		template <typename T>
		struct vec2_mul
		{
			static Vector2<T> call(Vector2<T> const & a, Vector2<T> const & b)
			{
				return Vector2<T>(a.x * b.x, a.y * b.y);
			}
		};

		template <typename T>
		struct vec2_div
		{
			static Vector2<T> call(Vector2<T> const & a, Vector2<T> const & b)
			{
				return Vector2<T>(a.x / b.x, a.y / b.y);
			}
		};
	}


	////////////////////////////////////////////////////////////
	// Constructors
	////////////////////////////////////////////////////////////

	template <typename T>
	 Vector2<T>::Vector2()
	{
		this->x = 0;
		this->y = 0;
	}

	template <typename T>
	 Vector2<T>::Vector2(Vector2<T> const & v)
	{
		this->x = v.x;
		this->y = v.y;
	}

	template <typename T>
	 Vector2<T>::Vector2(T const & a, T const & b) :
		x(a),
		y(b)
	{

	}

	 ////////////////////////////////////////////////////////////
	 // Explicit Conversion Constructors
	 ////////////////////////////////////////////////////////////

	template <typename T>
	template <typename U>
	 Vector2<T>::Vector2(U const & scalar) :
		x(static_cast<T>(scalar)),
		y(static_cast<T>(scalar))
	{

	}

	template <typename T>
	template <typename U>
	 Vector2<T>::Vector2(const Vector2<U>& v) :
		x(static_cast<T>(other.x)),
		y(static_cast<T>(other.y)),
		z(static_cast<T>(other.z))
	{

	}

	template <typename T>
	template <typename U>
	 Vector2<T>::Vector2(const Vector3<U>& v3) {
		this->x = static_cast<T>(v3.x);
		this->y = static_cast<T>(v3.y);
	}

	template <typename T>
	template <typename U>
	 Vector2<T>::Vector2(const Vector4<U>& v4) {
		this->x = static_cast<T>(v4.x);
		this->y = static_cast<T>(v4.y);
	}

	////////////////////////////////////////////////////////////
	// Operators
	////////////////////////////////////////////////////////////

	 // -- Relational Operators --

	 template <typename T>
	 bool Vector2<T>::operator<(const Vector2<T> other) const {

		 return (this->x < other.x) && (this->y < other.y);

	 }

	 template <typename T>
	 bool Vector2<T>::operator<=(const Vector2<T> other) const {

		 return (this->x <= other.x) && (this->y <= other.y);

	 }

	 template <typename T>
	 bool Vector2<T>::operator>(const Vector2<T> other) const {

		 return (this->x > other.x) && (this->y > other.y);

	 }

	 template <typename T>
	 bool Vector2<T>::operator>=(const Vector2<T> other) const {

		 return (this->x >= other.x) && (this->y >= other.y);

	 }


	// -- Unary Arithmetic Operators -- 

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator=(Vector2<U> const & v) {
		return Vector2<T>(v);
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator+=(U scalar) {
		return mathdetails::vec2_add<T>::call(*this, Vector2<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator+=(Vector2<U> const & v) {
		return mathdetails::vec2_add<T>::call(*this, Vector2<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator-=(U scalar) {
		return mathdetails::vec2_sub<T>::call(*this, Vector2<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator-=(Vector2<U> const & v) {
		return mathdetails::vec2_sub<T>::call(*this, Vector2<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator*=(U scalar) {
		return mathdetails::vec2_mul<T>::call(*this, Vector2<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator*=(Vector2<U> const& v) {
		return mathdetails::vec2_mul<T>::call(*this, Vector2<T>(v));
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator/=(U scalar) {
		return mathdetails::vec2_div<T>::call(*this, Vector2<T>(scalar));
	}

	template <typename T>
	template <typename U>
	Vector2<T> & Vector2<T>::operator/=(Vector2<U> const & v) {
		return mathdetails::vec2_div<T>::call(*this, Vector2<T>(v));
	}

	// -- Booleans Operators --

	template<typename T>
	bool operator ==(const Vector2<T>& left, const Vector2<T>& right) {

		return (left.x == right.x) && (left.y == right.y);

	}

	template<typename T>
	bool operator !=(const Vector2<T>& left, const Vector2<T>& right) {

		return (left.x != right.x) || (left.y != right.y);

	}

	// -- Unary operators --

	template <typename T>
	Vector2<T> operator+(Vector2<T> const & v) {
		return v;
	}

	template <typename T>
	Vector2<T> operator-(Vector2<T> const & v) {
		return Vector4<T>(0) -= v;
	}

	// -- Binary Arithmetic Operators --

	// +

	template <typename T>
	Vector2<T> operator+(Vector2<T> const & v, T scalar)
	{
		return Vector2<T>(v) += scalar;
	}


	template <typename T>
	Vector2<T> operator+(T scalar, Vector2<T> const & v) {

		return Vector2<T>(v) += scalar;

	}

	template <typename T>
	Vector2<T> operator+(Vector2<T> const & v1, Vector2<T> const & v2) {

		return Vector2<T>(v1) += v2;

	}

	// -

	template <typename T>
	Vector2<T> operator-(Vector2<T> const & v, T scalar) {

		return Vector2<T>(v) -= scalar;

	}

	template <typename T>
	Vector2<T> operator-(T scalar, Vector2<T> const & v) {

		return Vector2<T>(scalar) -= v;

	}

	template <typename T>
	Vector2<T> operator-(Vector2<T> const & v1, Vector2<T> const & v2) {

		return Vector2<T>(v1) -= v2;
	}

	// *

	template <typename T>
	Vector2<T> operator*(Vector2<T> const & v, T scalar) {

		return Vector2<T>(v) *= scalar;

	}

	template <typename T>
	Vector2<T> operator*(T scalar, Vector2<T> const & v) {

		return Vector2<T>(v) *= scalar;

	}

	template <typename T>
	Vector2<T> operator*(Vector2<T> const & v1, Vector2<T> const & v2) {

		return Vector2<T>(v1) *= v2;

	}

	// /

	template <typename T>
	Vector2<T> operator/(Vector2<T> const & v, T scalar) {

		return Vector2<T>(v1) /= scalar;

	}

	template <typename T>
	Vector2<T> operator/(T scalar, Vector2<T> const & v) {

		return Vector2<T>(scalar) /= v;

	}

	template <typename T>
	Vector2<T> operator/(Vector2<T> const & v1, Vector2<T> const & v2) {

		return Vector2<T>(v1) /= v2;

	}

}