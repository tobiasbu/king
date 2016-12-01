
#ifndef KING_VECTORTYPE_HPP
#define KING_VECTORTYPE_HPP

namespace king {

	// Vectors Types Predefinition

	template <typename T> class Vector2;
	template <typename T> class Vector3;
	template <typename T> class Vector4;

	// Most Commom Vectors Types

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2ui;

	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;
	
	typedef Vector4<float> Vector4f;

}

#endif