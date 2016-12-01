

#ifndef KING_ASSET_HPP
#define KING_ASSET_HPP

#include <string>
#include <king\Others\NonCopyable.hpp>
#include <king\Core\Object.hpp>

namespace king {

	
	enum AssetType {
		Texture,
		Font,
		Sound,
		Unknown
	};

	class AssetBase : public Object {

	private:

		std::string _name;
		std::string _path;

	public:

		std::string getName();
		std::string getPath();

	};

	template<class T>
	class Asset : public AssetBase, NonCopyable {

		
	private:

		AssetType _type;
		T * data;

	public:

		Asset(std::string path, AssetType, T *) {

			_id = id;
			_type = type;
			_path = FileUtils::getFileDirectory(path);
			_name = FileUtils::getFileName(path);
			_data = T;

		}

		AssetType getType() {

			
			return _type;

		}

		T * getData() {

			return _data;

		}


	};

}

#endif