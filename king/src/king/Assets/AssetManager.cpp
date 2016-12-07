
#include <king\Assets\AssetManager.hpp>
#include <king\Utils\FileUtils.hpp>
#include <iostream>

namespace king {

	namespace system {

		AssetManager::AssetManager() {

			//std::cout <<  _textures.getType() << std::endl;

			//.value() << " " << myExclusiveInt.id() << " " << myExclusiveInt2.id() << std::endl;
		}

		AssetManager::~AssetManager() {

			clear();

		}

		void AssetManager::eraseRegistry(std::map<std::string, std::unique_ptr<ResourceManagerBase>>::iterator it) {

			ResourceManagerBase * res = it->second.get();

			res->clear();

			it->second.release();

			delete res;



		}

		bool AssetManager::unregistry(std::string registry) {

			auto found = _resources.find(registry);

			if (found == _resources.end())
				return false;
			else {

				eraseRegistry(found);

				_resources.erase(found);

				return true;
			}


		}

		bool AssetManager::loadAsset(std::string) {

			return true;

		}

		bool AssetManager::exists(std::string registry) {

			size_t pos = registry.find_last_of("::");
			if (pos != std::string::npos)
				registry = registry.substr(pos + 1);

			std::map<std::string, std::unique_ptr < ResourceManagerBase > >::iterator it = _resources.find(registry);

			if (it == _resources.end())
				return false;
			else
				return true;


		}

		size_t AssetManager::count() {

			return _resources.size();

		}

		void AssetManager::clear() {

			for (std::map<std::string, std::unique_ptr < ResourceManagerBase > >::iterator it = _resources.begin(); it != _resources.end(); it++) {

				eraseRegistry(it);

			}

			//_resources.erase(_resources.begin(), _resources.end());

			_resources.clear();

		}
	}

	/*bool AssetManager::loadAsset(std::string path) {

		//sf::Font * font = new sf::Font();
		//Asset * asset = new Asset();
		//asset->_data = font;

		AssetType type = AssetType::Unknown;
		
		std::string extension = FileUtils::getFileExtension(path);
		bool create = false;
		void * data;


		std::cout << extension << std::endl;

		if (extension == "png") {
			sf::Texture * texture = new sf::Texture();

			create = texture->loadFromFile(path);
			
			data = texture;
			type = AssetType::Texture;
			asset = new Asset(_assets.size(), type, path, data);
		}

		if (create) {

			

			std::string name = FileUtils::getFileNameWithoutExtension(path);

			_assets.insert(std::make_pair(std::make_pair(name, type), asset));

			std::cout << "Asset " << name << " loaded" << std::endl;
		}
		

		return create;

	}

	bool AssetManager::unloadAsset(std::string name) {

		return true;

	}

	Asset * AssetManager::getAsset(std::string name, AssetType type) {

		auto found = _assets.find(std::make_pair(name, type));

		if (found == _assets.end())
			return nullptr;
		else
			return found->second;
	}*/


}