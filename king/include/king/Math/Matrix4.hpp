
#ifndef   KING_MATRIX4_HPP
#define   KING_MATRIX4_HPP

#include <king/Math/Vector4.hpp>
#include <king/Type/Types.hpp>

namespace king {

	class Matrix4 {

	public:

		/// Data Members
		union {
			struct {

				Vector4f rows[4];
			};
			float a[16];
		};

		/// Constructor

		Matrix4();
		Matrix4(const Matrix4 &);
		Matrix4(float diagonal);
		Matrix4(float * elements);
		Matrix4(const Vector4f & row0, const Vector4f & row1, const Vector4f & row2, const Vector4f & row4);

		/// Functions

		// Getters

		Vector4f getRow(uint32 index);
		Vector4f getColumn(uint32 index);

		// Setters

		void setRow(uint32 index,const Vector4f & row);
		void setColumn(uint32 index, const Vector4f & column);

		// Others
		Matrix4 & invert();

		std::string toString();

		/// Static Functions

		const static Matrix4 identity();

		/// Operators

		// Booleans

		bool friend operator==(Matrix4 const & m1, Matrix4 const & m2);
		bool friend operator!=(Matrix4 const & m1, Matrix4 const & m2);

		// Unary

		Matrix4 operator-(Matrix4 const & m);

		// Direct Access of an Columm

		Vector4f & operator[](const size_t index);
		const Vector4f & operator[](const size_t index) const;

		

	};

	

}

#endif