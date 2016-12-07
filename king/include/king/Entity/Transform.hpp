
#ifndef KING_TRANSFORM_HPP
#define KING_TRANSFORM_HPP

#include "king/Math/Vector3.hpp"
#include "king/Math/Matrix4.hpp"

namespace king {

	class Transform {

	private:

		Vector3f _position;
		Vector3f _scale;
		Vector3f _angle;

		Matrix4 _transform;

		void updateTransform();


	public:

		Vector3f getPosition();
		Vector3f getScale();
		Vector3f getEulerAngle();
		Matrix4 getMatrix();

	};

}

#endif