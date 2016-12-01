
#ifndef   KING_MATRIXTRANSFORM_HPP
#define   KING_MATRIXTRANSFORM_HPP

#include <king/Math/Vector3.hpp>
#include <king/Math/Matrix4.hpp>
#include <king/Math/Quaternion.hpp>

namespace king {

	namespace MatrixTransform {

		// Pushing operation in an matrix

		Matrix4 translate(Matrix4 const & mat, Vector3f const & translate);

		Matrix4 scale(Matrix4 const & mat, Vector3f const & scale);

		Matrix4 rotate(Matrix4 const & mat, float radians,  Vector3f const & axis);

		Matrix4 rotate(Matrix4 const & mat, Quaternion const & quat);


		// Just do one operation in identity matrix

		Matrix4 translate(const Vector3f & translation);

		Matrix4 scale(const Vector3f & scale);

		Matrix4 rotate(float radians, const Vector3f & axis);

		Matrix4 rotate(const Quaternion & quat);

		Matrix4 invert(const Matrix4 & mat);
		Matrix4 transpose(const Matrix4 & mat);

		// Camera

		Matrix4 orthographic();
		Matrix4 perspective();
		Matrix4 lookAt();

	}

}

#endif