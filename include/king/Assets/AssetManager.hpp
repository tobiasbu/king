



#ifndef KING_ASSETMANAGER_HPP
#define KING_ASSETMANAGER_HPP

#include <string>
#include <map>
#include <list>
#include <memory>

#include <SFML\Graphics.hpp>

#include <king\Others\Singleton.hpp>
#include <king\Others\NonCopyable.hpp>
#include <king\Assets\ResourceManager.hpp>
//#include <king\Others\Type.hpp>

namespace king {

	namespace adv {

		class AssetManager : public Singleton<AssetManager>, NonCopyable {



		private:


			//ResourceManager<sf::Texture> _textures;
			//std::map<unsigned int, Asset * > _assets;
			//template<typename T>
			std::map<std::string, std::unique_ptr<ResourceManagerBase>> _resources;

			void eraseRegistry(std::map<std::string, std::unique_ptr<ResourceManagerBase>>::iterator);
			//std::list<ResourceManager<T>> _list;

		public:

			AssetManager();
			~AssetManager();

			bool loadAsset(std::string);
			bool unloadAsset(std::string);
			bool unregistry(std::string);
			bool exists(std::string);
			size_t count();
			void clear();


			//void add(std::string, Asset);


			template<typename T>
			bool registry() {


				/*std::string str(TypeParseTraits<T>::name());

				// remove namespace if have
				size_t pos = str.find_last_of("::");
				if (pos != std::string::npos)
				str = str.substr(pos + 1);

				//std::cout << str << std::endl;


				auto found = _resources.find(str);*/

				if (exists<T>())
					return false;
				else {

					//ResourceManager<T> * manager = new ResourceManager<T>();

					std::string str(TypeParseTraits<T>::name());

					// remove namespace if have
					size_t pos = str.find_last_of("::");
					if (pos != std::string::npos)
						str = str.substr(pos + 1);

					std::unique_ptr<ResourceManager<T> > manager(new ResourceManager<T>());

					_resources.insert(std::make_pair(str, std::move(manager)));
				}

				return true;
			}

			template<typename T>
			bool unregistry() {

				std::string str(TypeParseTraits<T>::name());

				// remove namespace if have
				size_t pos = str.find_last_of("::");
				if (pos != std::string::npos)
					str = str.substr(pos + 1);

				//std::cout << str << std::endl;

				auto found = _resources.find(str);

				if (found == _resources.end())
					return false;
				else {

					eraseRegistry(it);
					/*ResourceManagerBase * res = found->second.get();
					ResourceManager<T> * resm = dynamic_cast<ResourceManager<T> *>(res);

					resm->clear();

					delete resm;

					found->second.release();

					_resources.erase(str);*/

				}

				return true;

			}

			template<typename T>
			bool exists()
			{
				const char * name = TypeParseTraits<T>::name();

				if (name == nullptr)
					return false;
				else {

					std::string str(name);

					return exists(str);
				}


			}

			template<typename T>
			ResourceManager<T> * getResourceManager() {


				std::string str(TypeParseTraits<T>().name());


				// remove namespace if have
				size_t pos = str.find_last_of("::");
				if (pos != std::string::npos)
					str = str.substr(pos + 1);

				auto found = _resources.find(str);

				if (found == _resources.end()) {

					std::cout << "KING::AssetManager: ResourceManager " << str << " not found." << std::endl;

					return nullptr;
				}
				else {

					ResourceManagerBase * res = found->second.get();

					//std::cout << "KING::AssetManager: ResourceManager " << str << " not found." << std::endl;

					return dynamic_cast<ResourceManager <T> *>(res);
				}

			}


			//Asset * getAsset(std::string, AssetType);
			//Asset * getAsset(unsigned int);


		};

#define KING_ASSETMANAGER adv::AssetManager::getInstance()


		
	};
}

#endif