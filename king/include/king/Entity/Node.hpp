


#ifndef KING_HIERACHYNODE_HPP
#define KING_HIERACHYNODE_HPP

#include <string>
#include <vector>

#include <king/Entity/Component.hpp>

namespace king {

	namespace system {
		class Hierarchy;
	}


	class Node : public Component {

		friend class system::Hierarchy;

	private:

		/// Member Data
		Node * _parent;
		

		/// Virtual Functions

		virtual void onUpdate();
		virtual void onEndUpdate();
		virtual void onFixedUpdate();

	protected:

		std::vector<Node *> _childs;

		/// Setters
		void setParent(Node * parent);
		Node() { _parent = nullptr; }

	public:

		Node(GameObject *);


		/// Getters
		Node * getParent();
		Node * getChild(int index);
		int getChildCount();

		/// Functions

		Node * find(Node *);
		Node * find(std::string name);

		void addChild(Node * child);
		void addChildAt(Node * child, int index);
		void removeChild(Node * child);
		void removeChildAt(int index);
		void detachChildren();
		bool isChildOf(Node * parent);


		

	};

}

#endif