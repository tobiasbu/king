


#ifndef KING_INSTANCE_HPP
#define KING_INSTANCE_HPP

#include <king/Entity/GameObject.hpp>
#include <king/Core/Hierarchy.hpp>

namespace king {

	class Instance {

	public:
		static GameObject * create();

		template<typename T>
		static GameObject * instantiate() {
			T * tempobj = new T();

			GameObject * gobj = dynamic_cast<GameObject *>(tempobj);

			system::Hierarchy::getInstance().addChild(&gobj->node);

			return gobj;
		}

		static void destroy(GameObject &);

	};

}

#endif