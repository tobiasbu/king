

#ifndef KING_ASYNCREQUEST_HPP
#define KING_ASYNCREQUEST_HPP

#include <king/Core/Object.hpp>

namespace king {

	//template<typename T>

	struct AsyncRequest {

	private:

		Object * _object;
		bool _loaded;

	public:

		bool isReady();
		Object * get();

	};

}

#endif