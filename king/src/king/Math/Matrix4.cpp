
#include <king/Math/Matrix4.hpp>

namespace king {

	const Matrix4 Matrix4::identity() {
		return Matrix4(1.0f);
	}

	Matrix4::Matrix4() {

		memset(a, 0, 4 * 4 * sizeof(float));

	}

	Matrix4::Matrix4(const Matrix4 & mat) {
		this->rows[0] = mat.rows[0];
		this->rows[1] = mat.rows[1];
		this->rows[2] = mat.rows[2];
		this->rows[3] = mat.rows[3];
	}

	Matrix4::Matrix4(float diagonal) {

		memset(a, 0, 4 * 4 * sizeof(float));
		a[0 + 0 * 4] = diagonal;
		a[1 + 1 * 4] = diagonal;
		a[2 + 2 * 4] = diagonal;
		a[3 + 3 * 4] = diagonal;

	}

	Matrix4::Matrix4(float * elements) {

		memcpy(this->a, elements, 4 * 4 * sizeof(float));

	}

	Matrix4::Matrix4(const Vector4f & row0, const Vector4f & row1, const Vector4f & row2, const Vector4f & row3) {

		rows[0] = row0;
		rows[1] = row1;
		rows[2] = row2;
		rows[3] = row3;

	}

	Vector4f Matrix4::getRow(uint32 index) {

		return rows[index];

	}

	Vector4f Matrix4::getColumn(uint32 index) {

		return Vector4f(a[index + 0 * 4], a[index + 1 * 4], a[index + 2 * 4], a[index + 3 * 4]);

	}

	void Matrix4::setRow(uint32 index, const Vector4f & row) {

		rows[index] = row;

	}

	void Matrix4::setColumn(uint32 index, const Vector4f & column) {

		a[index + 0 * 4] = column.x;
		a[index + 1 * 4] = column.y;
		a[index + 2 * 4] = column.z;
		a[index + 3 * 4] = column.w;

	}

	Matrix4 & Matrix4::invert() {

		float temp[16];

		temp[0] = a[5] * a[10] * a[15] -
			a[5] * a[11] * a[14] -
			a[9] * a[6] * a[15] +
			a[9] * a[7] * a[14] +
			a[13] * a[6] * a[11] -
			a[13] * a[7] * a[10];

		temp[4] = -a[4] * a[10] * a[15] +
			a[4] * a[11] * a[14] +
			a[8] * a[6] * a[15] -
			a[8] * a[7] * a[14] -
			a[12] * a[6] * a[11] +
			a[12] * a[7] * a[10];

		temp[8] = a[4] * a[9] * a[15] -
			a[4] * a[11] * a[13] -
			a[8] * a[5] * a[15] +
			a[8] * a[7] * a[13] +
			a[12] * a[5] * a[11] -
			a[12] * a[7] * a[9];

		temp[12] = -a[4] * a[9] * a[14] +
			a[4] * a[10] * a[13] +
			a[8] * a[5] * a[14] -
			a[8] * a[6] * a[13] -
			a[12] * a[5] * a[10] +
			a[12] * a[6] * a[9];

		temp[1] = -a[1] * a[10] * a[15] +
			a[1] * a[11] * a[14] +
			a[9] * a[2] * a[15] -
			a[9] * a[3] * a[14] -
			a[13] * a[2] * a[11] +
			a[13] * a[3] * a[10];

		temp[5] = a[0] * a[10] * a[15] -
			a[0] * a[11] * a[14] -
			a[8] * a[2] * a[15] +
			a[8] * a[3] * a[14] +
			a[12] * a[2] * a[11] -
			a[12] * a[3] * a[10];

		temp[9] = -a[0] * a[9] * a[15] +
			a[0] * a[11] * a[13] +
			a[8] * a[1] * a[15] -
			a[8] * a[3] * a[13] -
			a[12] * a[1] * a[11] +
			a[12] * a[3] * a[9];

		temp[13] = a[0] * a[9] * a[14] -
			a[0] * a[10] * a[13] -
			a[8] * a[1] * a[14] +
			a[8] * a[2] * a[13] +
			a[12] * a[1] * a[10] -
			a[12] * a[2] * a[9];

		temp[2] = a[1] * a[6] * a[15] -
			a[1] * a[7] * a[14] -
			a[5] * a[2] * a[15] +
			a[5] * a[3] * a[14] +
			a[13] * a[2] * a[7] -
			a[13] * a[3] * a[6];

		temp[6] = -a[0] * a[6] * a[15] +
			a[0] * a[7] * a[14] +
			a[4] * a[2] * a[15] -
			a[4] * a[3] * a[14] -
			a[12] * a[2] * a[7] +
			a[12] * a[3] * a[6];

		temp[10] = a[0] * a[5] * a[15] -
			a[0] * a[7] * a[13] -
			a[4] * a[1] * a[15] +
			a[4] * a[3] * a[13] +
			a[12] * a[1] * a[7] -
			a[12] * a[3] * a[5];

		temp[14] = -a[0] * a[5] * a[14] +
			a[0] * a[6] * a[13] +
			a[4] * a[1] * a[14] -
			a[4] * a[2] * a[13] -
			a[12] * a[1] * a[6] +
			a[12] * a[2] * a[5];

		temp[3] = -a[1] * a[6] * a[11] +
			a[1] * a[7] * a[10] +
			a[5] * a[2] * a[11] -
			a[5] * a[3] * a[10] -
			a[9] * a[2] * a[7] +
			a[9] * a[3] * a[6];

		temp[7] = a[0] * a[6] * a[11] -
			a[0] * a[7] * a[10] -
			a[4] * a[2] * a[11] +
			a[4] * a[3] * a[10] +
			a[8] * a[2] * a[7] -
			a[8] * a[3] * a[6];

		temp[11] = -a[0] * a[5] * a[11] +
			a[0] * a[7] * a[9] +
			a[4] * a[1] * a[11] -
			a[4] * a[3] * a[9] -
			a[8] * a[1] * a[7] +
			a[8] * a[3] * a[5];

		temp[15] = a[0] * a[5] * a[10] -
			a[0] * a[6] * a[9] -
			a[4] * a[1] * a[10] +
			a[4] * a[2] * a[9] +
			a[8] * a[1] * a[6] -
			a[8] * a[2] * a[5];

		float determinant = a[0] * temp[0] + a[1] * temp[4] + a[2] * temp[8] + a[3] * temp[12];
		determinant = 1.0f / determinant;

		for (int32 i = 0; i < 4 * 4; i++)
			a[i] = temp[i] * determinant;

		return *this;

	}

	std::string Matrix4::toString() {

		std::stringstream result;
		result << "(" << rows[0].x << ", " << rows[1].x << ", " << rows[2].x << ", " << rows[3].x << "), ";
		result << "(" << rows[0].y << ", " << rows[1].y << ", " << rows[2].y << ", " << rows[3].y << "), ";
		result << "(" << rows[0].z << ", " << rows[1].z << ", " << rows[2].z << ", " << rows[3].z << "), ";
		result << "(" << rows[0].w << ", " << rows[1].w << ", " << rows[2].w << ", " << rows[3].w << ")";
		return result.str();

	}

	Matrix4 Matrix4::operator -(Matrix4 const & m) {

		return Matrix4(-m[0], -m[1], m[2], -m[3]);

	}

	Vector4f & Matrix4::operator[](const size_t index) {

		assert(index < 4);

		return getColumn(index);

	}
	
	const Vector4f & Matrix4::operator[](const size_t index) const {

		assert(index < 4);

		return Vector4f(a[index + 0 * 4], a[index + 1 * 4], a[index + 2 * 4], a[index + 3 * 4]);

	}

	// -- Boolean operators --

	bool operator==(Matrix4 const & m1, Matrix4 const & m2) {

		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);

	}

	bool operator!=(Matrix4 const & m1, Matrix4 const & m2) {
		                                  
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);

	}

	

}