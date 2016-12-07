

#ifndef KING_GAMEOBJECT_HPP
#define KING_GAMEOBJECT_HPP

//#include <king/Type/Types.hpp>
#include <king/Core/Object.hpp>
#include <king/Entity/Component.hpp>
#include <king/Entity/Node.hpp>
#include <king/Entity/Transform.hpp>
#include <unordered_map>

namespace king {

	namespace system {
		class Hierarchy;
	}

	class GameObject : public Object {

	
		friend class system::Hierarchy;

	private:
		
		/// Member Data

		bool _active = true;
		std::string _name;

		template <typename T>
		const T * internalGetComponent() const {
			//ComponentType* type = T::GetStaticType();
			std::string t = T.getType();
			auto it = m_Components.find(t);
			if (it == m_Components.end())
				return nullptr;
			return (T*)it->second;
		}

		std::unordered_map<std::string, Component *> _components;


	public:

		/// Constructors

		GameObject();
		GameObject(std::string name);
		~GameObject();

		/// Data
		Transform transform;
		Node node;

		/// Functions

		// Setters
		void setName(std::string);
		void setActive(bool);

		// Getters
		std::string getName();
		bool getActive();

		
		// Hierarchy functions
		virtual void preload() {}
		virtual void start() {}
		virtual void update() {}
		

		template <typename T>
		T & addComponent() {

			T * compo = new T();



		}

		template <typename T>
		const T * getComponent() const {

			return internalGetComponent<T>();

		}

		template <typename T>
		T * getComponent() {

			return internalGetComponent<T>();

		}

		template <typename T>
		void removeComponent() {

		}

		template <typename T>
		bool hasComponent() {

			auto it = _components.find(T);

			if (it == _components.end())
				return false;
			else
				return true;

		}


		
	};

}

#endif