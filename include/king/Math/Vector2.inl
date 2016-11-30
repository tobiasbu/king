
////////////////////////////////////////////////////////////
// Constructors
////////////////////////////////////////////////////////////

template <typename T>
inline Vector2<T>::Vector2() : 
x(0),
y(0)
{

}

template <typename T>
inline Vector2<T>::Vector2(T const & a, T const & b) : 
x(a),
y(b)
{

}
template <typename T>
template <typename U>
inline Vector2<T>::Vector2(U const & scalar) : 
x(static_cast<T>(scalar)),
y(static_cast<T>(scalar))
{

}


template <typename T>
template <typename U>
inline Vector2<T>::Vector2(const Vector2<U>& vector) :
x(static_cast<T>(other.x)),
y(static_cast<T>(other.y)),
z(static_cast<T>(other.z))
{

}
