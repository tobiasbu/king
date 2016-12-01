


#ifndef KING_OBJECT_HPP
#define KING_OBJECT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
//#include "UniqueIdentifier.hpp"
#include <string>

namespace king {

	////////////////////////////////////////////////////////////
	/// \brief Base class for every object on King Engine.
	///
	////////////////////////////////////////////////////////////
	class Object {

	friend class UniqueIdentifier;

	private:

		////////////////////////////////////////////////////////////
		// Private data
		////////////////////////////////////////////////////////////
		unsigned int _id; /// unique identifier provide by UniqueIdentifier class.
		std::string _type; /// type as string of object

	public:

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Creates an empty Object;
		///
		////////////////////////////////////////////////////////////
		Object();

		////////////////////////////////////////////////////////////
		/// \brief Get the unique identifier of this instance.
		///
		/// \return unique identifier
		///
		////////////////////////////////////////////////////////////
		unsigned int getID();

		////////////////////////////////////////////////////////////
		/// \brief Get the name of type of object
		///
		/// \return type name of object
		///
		////////////////////////////////////////////////////////////
		std::string getType();

	};

}

#endif