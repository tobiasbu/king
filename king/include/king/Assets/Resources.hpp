
#ifndef KING_RESOURCES_HPP
#define KING_RESOURCES_HPP

#include <string>

#include "Asset.hpp"
#include "AsyncRequest.hpp"
#include "Type.hpp"

namespace king {

	class Resources {
	
		public:

		

		static AssetBase * load(std::string path);
		static AssetBase * load(std::string path, std::string type);
		static AsyncRequest * loadAsync(std::string);
		static void addLoadAsyncQueue(std::string);

		template<typename T>
		static T * get(std::string assetName) {

			

		}

		template<typename T>
		static T * load(std::string path) {


			return nullptr;
		}

	};

}

#endif