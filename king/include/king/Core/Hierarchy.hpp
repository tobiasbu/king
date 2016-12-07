


#ifndef KING_HIERARCHY_HPP
#define KING_HIERARCHY_HPP

#include <king/Entity/Node.hpp>
#include <king/Others/Singleton.hpp>

#include <vector>

namespace king {

	namespace system {

		class Hierarchy : public Node, public Singleton<Hierarchy> {

		private:

			void setActive(bool active) {}
			//std::vector<Node *> _gameObjects;

		public:
			Hierarchy();
			~Hierarchy();


			void onUpdate();
			void onEndUpdate();
			void onFixedUpdate();

			void clear();


		};

	}

}
#endif