
#ifndef   KING_FILEUTILS_HPP
#define   KING_FILEUTILS_HPP

#include <string>


namespace king {

	namespace FileUtils {
	
		std::string getFileName(std::string);

		std::string getFileNameWithoutExtension(std::string);

		std::string getFileExtension(std::string);

		std::string getFileDirectory(std::string);

		
	
	}


}

#endif