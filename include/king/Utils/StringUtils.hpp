

#ifndef   KING_STRINGUTIL_HPP
#define   KING_STRINGUTIL_HPP

#define _CRT_SECURE_NO_WARNINGS

#include <king\KingTypes.hpp>
#include <king\Math\Vector3.hpp>
#include <string>

namespace king {

	namespace StringUtils {

		static std::string convert(bool);
		static std::string convert(int32);
		static std::string convert(uint32);
		static std::string convert(float);
		static std::string convert(double);
		

		static bool parseBool(std::string);
		static int32 parseInt(std::string);
		static uint32 parseUint(std::string);
		static float parseFloat(std::string);
		static double parseDouble(std::string);


		Vector3f parseVector3f(std::string);
		
		std::string remove(std::string, std::string);
		std::string charToString(char * charArray, int size);
		std::string charToString(const unsigned char * charuArray);
		char * stringToChar(std::string);
	};


	

}



#endif