


#ifndef KING_TYPE_HPP
#define KING_TYPE_HPP

#include <king/Utils/StringUtils.hpp>

#include <cstdlib>
#include <string>

//#include <SFML\Graphics.hpp>

// FUTURE IMPLEMENTATION - meta programming

namespace king {

	template<typename T>
	struct Type
	{
		//static size_t counter;
	private:

		//static size_t _id;
		T val;

	public:

		//static void identifier() {}

		/*size_t id() {
			//static size_t _id = _id++;
			return reinterpret_cast<size_t>(&Type<T>::identifier);
			}*/

		T value()
		{
			return val;
		}

		T & operator =(const T & other) {
			val = other;
			return val;
		}

		T & operator ()() {
			return val;
		}

	};

	/*template<typename T>
	struct TypeParseTraits;

	#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
	{ static const char* name; } ; const char* TypeParseTraits<X>::name = #X


	REGISTER_PARSE_TYPE(int);
	REGISTER_PARSE_TYPE(double);*/

	template<typename T>
	struct TypeParseTraits
	{

	private:
		static char * _name;

	public:
		TypeParseTraits()   {}

		TypeParseTraits(const char * name)   {
			_name = (char *)name;
		}

		const char * operator()(){
			return (const char *)_name;//&name[i];
		}

		static const char * name() {

			if (_name == nullptr)
				std::cout << "Type was not defined" << std::endl;

			return (const char *)_name;
		}
		
		static std::string registerType() {

			std::string tname;

			

			if (TypeParseTraits<T>::_name == nullptr) {
				tname = typeid(T).name();
				//parser._name = const_cast<char *>(tname.c_str());
				//TypeParseTraits<T> parser(tname.c_str());
				tname = StringUtils::remove(tname, "class ");
				char * name = StringUtils::stringToChar(tname);
				std::cout << "Type registered: " << name << std::endl;
				TypeParseTraits<T>::_name = name;
			}
			else {

				std::cout << TypeParseTraits<T>::name() << " has been registered." << std::endl;

				return TypeParseTraits<T>::name();

			}
				


			return  tname;
			/*std::string tname;

			if (X.name != nullptr) {
			int status;
			tname = typeid(X).name();
			/*char *demangled_name = abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status);
			if (status == 0) {
			tname = demangled_name;
			std::free(demangled_name);
			}
			REGISTER_PARSE_TYPE(X);
			//template <> const char* TypeParseTraits<X>::name = #X;
			}
			else
			return X.name;

			return tname;*/


		}
		
		

	};

	template<typename T>
	char * TypeParseTraits<T>::_name = nullptr;


	// in c-file
#define KING_REGISTER_PARSE_TYPE(X) \
    template <> char* TypeParseTraits<X>::_name = #X


	


	
}

#endif