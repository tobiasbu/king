

//#include "Vector3.hpp"

////////////////////////////////////////////////////////////
// Constructors
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>::Vector3() :
x(0),
y(0),
z(0)
{

}

////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>::Vector3(T const & a, T const & b) :
x(a),
y(b),
z(0)
{

}

////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>::Vector3(T const & a, T const & b, T const & c) :
x(a),
y(b),
z(c)
{

}

////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
inline Vector3<T>::Vector3(U const & scalar) :
x(static_cast<T>(scalar)),
y(static_cast<T>(scalar)),
z(static_cast<T>(scalar))
{

}

////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
inline Vector3<T>::Vector3(const Vector3<U>& other) :
x(static_cast<T>(other.x)),
y(static_cast<T>(other.y)),
z(static_cast<T>(other.z))
{
}

////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
template<typename T>
inline Vector3<T> operator +(const Vector3<T>& self, const Vector3<T>& other) {

	return Vector3<T>(self.x + other.x, self.y + other.y, self.z + other.z);

}


////////////////////////////////////////////////////////////
template<typename T>
inline Vector3<T>& operator +=(Vector3<T>& self, const Vector3<T>& other) {

	self.x += other.x;
	self.y += other.y;
	self.z += other.z;

	return self;

}

////////////////////////////////////////////////////////////
template<typename T>
inline Vector3<T> operator -(const Vector3<T>& self, const Vector3<T>& other) {

	return Vector3<T>(self.x - other.x, self.y - other.y, self.z - other.z);

}

////////////////////////////////////////////////////////////
template<typename T>
inline Vector3<T>& operator -=(Vector3<T>& self, const Vector3<T>& other) {

	self.x -= other.x;
	self.y -= other.y;
	self.z -= other.z;

	return self;

}

////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator -(const Vector3<T>& self)
{
	return Vector3<T>(-self.x, -self.y, -self.z);
}

/// Values and Vectors Operators (it should not be overloaded)

/*
template<typename T>
inline Vector3<T> operator +(const Vector3<T>& self, const T& value) {

	return Vector3<T>(self.x + value, self.y + value, self.z + value);

}

template <typename T>
inline Vector3<T>& operator -=(Vector3<T>& self, const T & value)
{
self.x -= value;
self.y -= value;
self.z -= value;

return self;
}

template <typename T>
inline Vector3<T>& operator +=(Vector3<T>& self, const T & value)
{
self.x += value;
self.y += value;
self.z += value;

return self;
}
*/