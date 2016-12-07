
#include <king/Entity/Node.hpp>
#include <king/Entity/GameObject.hpp>

#include <algorithm>
#include <assert.h>

namespace king {

	Node::Node(GameObject * gameObject) {

		_gameObject = gameObject;
		_parent = nullptr;

	}

	void Node::setParent(Node * parent) {

		_parent = parent;

	}

	Node * Node::getParent() {

		return _parent;

	}

	Node * Node::getChild(int index) {

		assert(index < _childs.size() && _childs.size() > 0);

		return _childs[index];

	}

	int Node::getChildCount() {

		return _childs.size();

	}

	Node * Node::find(Node * child) {

		std::vector<Node *>::iterator it = std::find(_childs.begin(), _childs.end(), child);

		if (it != _childs.end())
			return (*it);
		else
			return nullptr;
	}

	Node * Node::find(std::string name) {

		

		for (int i = 0; i < _childs.size(); i++) {
			if (name == _childs[i]->_gameObject->getName())
				return _childs[i];
		}

		return nullptr;
	}

	void  Node::addChild(Node * child) {

		this->addChildAt(child, _childs.size());

	}

	void Node::addChildAt(Node * child, int index = 0) {

		assert(index >= 0 && index <= _childs.size());

		

		if (child->getParent() != nullptr)
		{
			child->getParent()->removeChild(child);
		}


		child->setParent(this);

		if (index >= _childs.size() - 1)
			_childs.push_back(child);
		else
			_childs.insert(_childs.begin() + index, child);

	}

	void Node::removeChild(Node * child) {

		std::vector<Node *>::iterator it = std::find(_childs.begin(), _childs.end(), child);

		if (it != _childs.end())
			_childs.erase(it);
		

	}

	void Node::removeChildAt(int index) {

		Node * child = this->getChild(index);

		child->setParent(nullptr);
		
		_childs.erase(_childs.begin() + index);
		//return child;

	}

	void Node::detachChildren() {


		std::vector<Node *>::iterator it;

		while (!_childs.empty()) {

			(*it)->setParent(nullptr);
			_childs.pop_back();
			it++;
		}
	}

	bool Node::isChildOf(Node * parent) {

		return (_parent == parent);

	}

	void Node::onUpdate() {

		for (int i = 0; i < _childs.size(); i++) {
			if (_childs[i]->getGameObject()->getActive())
				_childs[i]->getGameObject()->update();
		}

	}

	void Node::onEndUpdate() {

	}

	void Node::onFixedUpdate() {

	}
}