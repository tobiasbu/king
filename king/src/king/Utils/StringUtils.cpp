
#include <king/Utils/StringUtils.hpp>
#include <algorithm>
#include <sstream>
#include <cstring>

namespace king {


	std::string StringUtils::convert(bool value) {

		std::stringstream str;

		if (value)
			str << "true";
		else
			str << "false";
		
		return str.str();

	}

	std::string StringUtils::convert(int32 value) {

		std::stringstream str;
		str << value;
		return str.str();

	}

	std::string StringUtils::convert(uint32 value) {

		std::stringstream str;
		str << value;
		return str.str();

	}

	std::string StringUtils::convert(float value) {

		std::stringstream str;
		str << value;
		return str.str();

	}

	std::string StringUtils::convert(double value) {

		std::stringstream str;
		str << value;
		return str.str();

	}

	bool StringUtils::parseBool(std::string value) {

		bool r = false;

		std::transform(value.begin(), value.end(), value.begin(), tolower);

		if (value == "true" || value == "1" || value == "on" || value == "active")
			r = true;
		else if (value == "false" || value == "0" || value == "off" || value == "desactive")
			r = false;

	
		return r;
	}

	int32 StringUtils::parseInt(std::string value) {

		int r = 0;
		std::istringstream str(value);

		str >> r;

		return r;

	}

	uint32 StringUtils::parseUint(std::string value) {

		unsigned int r = 0;
		std::istringstream str(value);

		str >> r;

		return r;

	}

	float StringUtils::parseFloat(std::string value) {

		float r = 0;
		std::istringstream str(value);

		str >> r;

		return r;

	}

	double StringUtils::parseDouble(std::string value) {

		double r = 0;
		std::istringstream str(value);

		str >> r;

		return r;

	}

	Vector3f StringUtils::parseVector3f(std::string value) {

		Vector3f r;

		size_t commaOffset = value.find_first_of(',', 0);
		if (commaOffset != std::string::npos)
		{
			float x = parseFloat(value.substr(0, commaOffset));

			// Try to find the next comma
			size_t commaOffset2 = value.find_first_of(',', commaOffset + 1);
			if (commaOffset2 != std::string::npos)
			{
				float y = parseFloat(value.substr(commaOffset + 1, commaOffset2));
				float z = parseFloat(value.substr(commaOffset2 + 1));

				// Now that all 3 values have been parsed, return the Vector3f found

				r.x = x;
				r.y = y;
				r.z = z;
			}
		}


		return r;
	}

	std::string StringUtils::charToString(char * charArray, int size) {

		std::stringstream buffer;

		for (int ch = 0; ch < size; ch++) {
			if (charArray[ch] == '\0') { break; }
			buffer << charArray[ch];

		}

		return buffer.str();
	}

	std::string StringUtils::charToString(const unsigned char * charuArray) {

		std::stringstream buffer;

		if (charuArray != nullptr) {

			int cidx = 0;

			while (charuArray[cidx] != '\0') {
				buffer << charuArray[cidx];
				cidx++;
			}

			return buffer.str();
		}
		else
			return "";

		
	}

	char * StringUtils::stringToChar(std::string str) {
		
		//const char *cstr = str.c_str();
		char *cstr = new char[str.length() + 1];
		return strcpy(cstr, str.c_str());
		
	}

	std::string StringUtils::remove(std::string source, std::string substr) {

		 
		size_t pos  = source.find(substr);

		if (pos == std::string::npos)
			return source;
		else {
			return source.erase(pos, substr.length());
		}

	}
	

}