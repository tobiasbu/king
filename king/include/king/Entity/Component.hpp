

#ifndef KING_COMPONENT_HPP
#define KING_COMPONENT_HPP

#include <string>

namespace king {

	class GameObject;

	class Component {

	private:

		std::string _type;
		bool _active = true;

	protected:
		GameObject * _gameObject;

		Component() { _gameObject = nullptr; }


	public:

		Component(GameObject * gameObject);
		~Component();

		
		virtual void setActive(bool active);
		bool getActive();
		GameObject * getGameObject();
	};

}

#endif