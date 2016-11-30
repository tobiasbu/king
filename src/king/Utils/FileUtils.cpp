
#include <king\Utils\FileUtils.hpp>

namespace king {


	std::string FileUtils::getFileName(std::string path) {


		int i = path.find_last_of('\\');
		

		if (i != std::string::npos)
			return path.substr(i + 1); // f contains the result :)
		else {
			i = path.find_last_of('/');
			return path.substr(i + 1);
		}
		
		return path;

	};

	std::string FileUtils::getFileNameWithoutExtension(std::string fname) {

		fname = getFileName(fname);

		size_t pos = fname.rfind(("."));
		if (pos == std::string::npos)  //No extension.
			return fname;

		if (pos == 0)    //. is at the front. Not an extension.
			return fname;

		return fname.substr(0, pos);

	}

	std::string FileUtils::getFileExtension(std::string fname) {

		size_t pos = fname.find_last_of(".");

		if (pos != std::string::npos)
			return fname.substr(pos + 1);

		return "";

	}

	std::string FileUtils::getFileDirectory(std::string path) {

		std::string dir = path;
		bool found = false;

		for (int i = path.length() - 1; i >= 0; i--)
		{
			if (i == 0) {
				dir = "";
				break;
			}
			else {
				if (path[i] == '\\' || path[i] == '/') {
					dir = path.substr(0, i + 1);
					break;
				}
			}
		}

		return dir;

	}


}