
#include <king/Math/MatrixTransform.hpp>

namespace king {

	Matrix4  MatrixTransform::translate(Matrix4 const & mat, Vector3f const & vec) {
		Matrix4 r(mat);

		//r[3] = mat[0] * vec[0] + mat[1] * vec[1] + mat[2] * vec[2] + mat[3];

		return r;
	}

	Matrix4  MatrixTransform::scale(Matrix4 const & mat, Vector3f const & vec) {

		Matrix4 r(1.0f);

		return r;

	}

	Matrix4  MatrixTransform::rotate(Matrix4 const & mat, float radians, Vector3f const & axis);

	Matrix4  MatrixTransform::rotate(Matrix4 const & mat, Quaternion const & quat);

	Matrix4 MatrixTransform::translate(const Vector3f & translation) {

		Matrix4 r(1.0f);

		r.a[3 + 0 * 4] = translation.x;
		r.a[3 + 1 * 4] = translation.y;
		r.a[3 + 2 * 4] = translation.z;

		return r;

	}

	Matrix4 MatrixTransform::scale(const Vector3f & scale) {

		Matrix4 r(1.0f);

		r.a[0 + 0 * 4] = scale.x;
		r.a[1 + 1 * 4] = scale.y;
		r.a[2 + 2 * 4] = scale.z;

		return r;

	}

	Matrix4 MatrixTransform::rotate(float radians, const Vector3f & axis) {

		Matrix4 r(1.0f);

		return r;

	}

	Matrix4 MatrixTransform::rotate(const Quaternion & quat);

	Matrix4 MatrixTransform::invert(const Matrix4 & mat) {

		Matrix4 r;
		           
		r.a[0] = mat.a[5] * mat.a[10] * mat.a[15] -
			mat.a[5] * mat.a[11] * mat.a[14] -
			mat.a[9] * mat.a[6] * mat.a[15] +
			mat.a[9] * mat.a[7] * mat.a[14] +
			mat.a[13] * mat.a[6] * mat.a[11] -
			mat.a[13] * mat.a[7] * mat.a[10];

		r.a[4] = -mat.a[4] * mat.a[10] * mat.a[15] +
			mat.a[4] * mat.a[11] * mat.a[14] +
			mat.a[8] * mat.a[6] * mat.a[15] -
			mat.a[8] * mat.a[7] * mat.a[14] -
			mat.a[12] * mat.a[6] * mat.a[11] +
			mat.a[12] * mat.a[7] * mat.a[10];

		r.a[8] = mat.a[4] * mat.a[9] * mat.a[15] -
			mat.a[4] * mat.a[11] * mat.a[13] -
			mat.a[8] * mat.a[5] * mat.a[15] +
			mat.a[8] * mat.a[7] * mat.a[13] +
			mat.a[12] * mat.a[5] * mat.a[11] -
			mat.a[12] * mat.a[7] * mat.a[9];

		r.a[12] = -mat.a[4] * mat.a[9] * mat.a[14] +
			mat.a[4] * mat.a[10] * mat.a[13] +
			mat.a[8] * mat.a[5] * mat.a[14] -
			mat.a[8] * mat.a[6] * mat.a[13] -
			mat.a[12] * mat.a[5] * mat.a[10] +
			mat.a[12] * mat.a[6] * mat.a[9];

		r.a[1] = -mat.a[1] * mat.a[10] * mat.a[15] +
			mat.a[1] * mat.a[11] * mat.a[14] +
			mat.a[9] * mat.a[2] * mat.a[15] -
			mat.a[9] * mat.a[3] * mat.a[14] -
			mat.a[13] * mat.a[2] * mat.a[11] +
			mat.a[13] * mat.a[3] * mat.a[10];

		r.a[5] = mat.a[0] * mat.a[10] * mat.a[15] -
			mat.a[0] * mat.a[11] * mat.a[14] -
			mat.a[8] * mat.a[2] * mat.a[15] +
			mat.a[8] * mat.a[3] * mat.a[14] +
			mat.a[12] * mat.a[2] * mat.a[11] -
			mat.a[12] * mat.a[3] * mat.a[10];

		r.a[9] = -mat.a[0] * mat.a[9] * mat.a[15] +
			mat.a[0] * mat.a[11] * mat.a[13] +
			mat.a[8] * mat.a[1] * mat.a[15] -
			mat.a[8] * mat.a[3] * mat.a[13] -
			mat.a[12] * mat.a[1] * mat.a[11] +
			mat.a[12] * mat.a[3] * mat.a[9];

		r.a[13] = mat.a[0] * mat.a[9] * mat.a[14] -
			mat.a[0] * mat.a[10] * mat.a[13] -
			mat.a[8] * mat.a[1] * mat.a[14] +
			mat.a[8] * mat.a[2] * mat.a[13] +
			mat.a[12] * mat.a[1] * mat.a[10] -
			mat.a[12] * mat.a[2] * mat.a[9];

		r.a[2] = mat.a[1] * mat.a[6] * mat.a[15] -
			mat.a[1] * mat.a[7] * mat.a[14] -
			mat.a[5] * mat.a[2] * mat.a[15] +
			mat.a[5] * mat.a[3] * mat.a[14] +
			mat.a[13] * mat.a[2] * mat.a[7] -
			mat.a[13] * mat.a[3] * mat.a[6];

		r.a[6] = -mat.a[0] * mat.a[6] * mat.a[15] +
			mat.a[0] * mat.a[7] * mat.a[14] +
			mat.a[4] * mat.a[2] * mat.a[15] -
			mat.a[4] * mat.a[3] * mat.a[14] -
			mat.a[12] * mat.a[2] * mat.a[7] +
			mat.a[12] * mat.a[3] * mat.a[6];

		r.a[10] = mat.a[0] * mat.a[5] * mat.a[15] -
			mat.a[0] * mat.a[7] * mat.a[13] -
			mat.a[4] * mat.a[1] * mat.a[15] +
			mat.a[4] * mat.a[3] * mat.a[13] +
			mat.a[12] * mat.a[1] * mat.a[7] -
			mat.a[12] * mat.a[3] * mat.a[5];

		r.a[14] = -mat.a[0] * mat.a[5] * mat.a[14] +
			mat.a[0] * mat.a[6] * mat.a[13] +
			mat.a[4] * mat.a[1] * mat.a[14] -
			mat.a[4] * mat.a[2] * mat.a[13] -
			mat.a[12] * mat.a[1] * mat.a[6] +
			mat.a[12] * mat.a[2] * mat.a[5];

		r.a[3] = -mat.a[1] * mat.a[6] * mat.a[11] +
			mat.a[1] * mat.a[7] * mat.a[10] +
			mat.a[5] * mat.a[2] * mat.a[11] -
			mat.a[5] * mat.a[3] * mat.a[10] -
			mat.a[9] * mat.a[2] * mat.a[7] +
			mat.a[9] * mat.a[3] * mat.a[6];

		r.a[7] = mat.a[0] * mat.a[6] * mat.a[11] -
			mat.a[0] * mat.a[7] * mat.a[10] -
			mat.a[4] * mat.a[2] * mat.a[11] +
			mat.a[4] * mat.a[3] * mat.a[10] +
			mat.a[8] * mat.a[2] * mat.a[7] -
			mat.a[8] * mat.a[3] * mat.a[6];

		r.a[11] = -mat.a[0] * mat.a[5] * mat.a[11] +
			mat.a[0] * mat.a[7] * mat.a[9] +
			mat.a[4] * mat.a[1] * mat.a[11] -
			mat.a[4] * mat.a[3] * mat.a[9] -
			mat.a[8] * mat.a[1] * mat.a[7] +
			mat.a[8] * mat.a[3] * mat.a[5];

		r.a[15] = mat.a[0] * mat.a[5] * mat.a[10] -
			mat.a[0] * mat.a[6] * mat.a[9] -
			mat.a[4] * mat.a[1] * mat.a[10] +
			mat.a[4] * mat.a[2] * mat.a[9] +
			mat.a[8] * mat.a[1] * mat.a[6] -
			mat.a[8] * mat.a[2] * mat.a[5];

		

		float determinant = mat.a[0] * r.a[0] + mat.a[1] * r.a[4] + mat.a[2] * r.a[8] + mat.a[3] * r.a[12];
		determinant = 1.0f / determinant;

		for (int32 i = 0; i < 4 * 4; i++)
			r.a[i] = r.a[i] * determinant;

		return r;

	}

	Matrix4 MatrixTransform::transpose(const Matrix4 & mat) {

		return Matrix4(
			Vector4f(mat.rows[0].x, mat.rows[1].x, mat.rows[2].x, mat.rows[3].x),
			Vector4f(mat.rows[0].y, mat.rows[1].y, mat.rows[2].y, mat.rows[3].y),
			Vector4f(mat.rows[0].z, mat.rows[1].z, mat.rows[2].z, mat.rows[3].z),
			Vector4f(mat.rows[0].w, mat.rows[1].w, mat.rows[2].w, mat.rows[3].w)
			);

	}

	Matrix4 MatrixTransform::orthographic();

	Matrix4 MatrixTransform::perspective();

	Matrix4 MatrixTransform::lookAt();

	

}