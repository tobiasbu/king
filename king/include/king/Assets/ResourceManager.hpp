
#ifndef KING_RESOURCEMANAGER_HPP
#define KING_RESOURCEMANAGER_HPP

#include <map>

//#include "Object.hpp"
#include <king\Assets\Asset.hpp>


namespace king {

	class ResourceManagerBase : public Object, NonCopyable {

	public:
		virtual int count() = 0;
		virtual void clear() = 0;

	};

	template <class T>
	class ResourceManager : public ResourceManagerBase {

	private:


		std::map<std::string, Asset<T *> *> _resources;

	public:

		
		~ResourceManager() {
			clear();
		}

		
		Asset<T *> * get(const std::string & name) {

			auto found = _resources.find(name);

			if (found == _assets.end())
				return nullptr;
			else
				return found->second;

		}

		T * getData(const std::string & name) {

		}
		//Asset<T *> * operator[];

		virtual bool load(const std::string & path) {

			return true;

		}

		bool add(const std::string & name, T * obj) {

			if (T != nullptr) {

				Asset<T> * asset;
				asset = new Asset<T>(name, type, obj);

				std::string assetname = FileUtils::getFileNameWithoutExtension(path);

				_resources.insert(std::make_pair(assetname,asset));

				return true;
			}
			else
			return false;

		}

		void remove(const std::string & name) {

		}

		int count() {

			return _resources.size();

		}

		void clear() {

			/*for (std::map<std::string, std::unique_ptr < ResourceManagerBase > >::iterator it = _resources.begin(); it != _resources.end(); it++) {

				eraseRegistry(it);

			}*/

		}

		

	};
}

#endif