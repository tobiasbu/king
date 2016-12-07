


#ifndef KING_TYPETRAITS_HPP
#define KING_TYPETRAITS_HPP

#include <king/Utils/StringUtils.hpp>

#include <cstdlib>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <iostream>

//#include <SFML\Graphics.hpp>

// FUTURE IMPLEMENTATION - meta programming



/*#define KING_TYPE_NAME(a) #a


namespace king {

	namespace system {

		enum TypeCategory {
			Unknown,
			Integral,
			FloatingPoint,
			Enum,
			Class
		};

		template<typename T>
		struct Type
		{
		public:

			//Type() {
			//	if (this->_name == nullptr)
			//		this->reg();
			//}



			//truct TypeProperties {
			//	bool isUnsigned;
			//bool isSigend;
			//bool isConst;

			//}


			typedef T value_type;

			//KING_PARSE_TYPE(X)

			static const char * name() {

				assert(_name != nullptr && "Type was not defined");


				return (const char *)_name;
			}

			static const char * namespaces() {

				assert(_namespaces != nullptr && "Type was not defined or type has no namespace.");


				return (const char *)_namespaces;
			}

			static const TypeCategory category() {

				return _category;

			}

			static void reg(std::string rename = "") {



				if (Type<T>::_name == nullptr) {

					char * name;

					if (rename.length() == 0) {
						//const char * n =//KING_TYPE_NAME(T); // typeid(T).name();
						KING_TYPE_SET_NAME(T); //TINFO(T);
						name = Type<T>::_name;
						/*	std::string tname(n);

						tname = StringUtils::remove(tname, "class ");

						size_t pos = tname.find_last_of("::");
						if (pos != std::string::npos) {
							//tname.erase(pos);
							std::string namesp = tname;

							//Type<T>::_namespaces = StringUtils::stringToChar(namesp.erase(pos + 1));
							//std::cout << namesp << std::endl;

							tname = tname.substr(pos + 1);
						}

						name = StringUtils::stringToChar(tname);





					}
					else {
						name = const_cast<char *>(rename.c_str());
					}

					//Type<T>::_name = name;

					std::cout << "King::Type Registered: " << name << std::endl;


					Type<T>::_category = TypeCategory::Unknown;

					if (std::is_class<T>())
						Type<T>::_category = TypeCategory::Class;
					else if (std::is_enum<T>())
						Type<T>::_category = TypeCategory::Enum;
					else if (std::is_integral<T>()) {
						Type<T>::_category = TypeCategory::Integral;
					}
					else if (std::is_floating_point<T>()) {
						Type<T>::_category = TypeCategory::FloatingPoint;
					}

					//bool _unsigned = std::is_unsigned<T>();
					//bool _signed = std::is_signed<T>();
					//int size = sizeof(T);


				}
				else {
					std::cout << "King::Type " << name() << " has been registered." << std::endl;
				}

			}


		private:




			//static size_t _id;

			static TypeCategory _category;
			static char * _name;
			//static char * _namespaces;


			//static void identifier() {}

			//size_t id() {
			////static size_t _id = _id++;
			//return reinterpret_cast<size_t>(&Type<T>::identifier);
			//}


		};

		template<typename T>
		char * Type<T>::_name = nullptr;

		template<typename T>
		char * Type<T>::_namespaces = nullptr;

		template<typename T>
		TypeCategory Type<T>::_category = TypeCategory::Unknown;*/



	
	//void check() { Type<X>::_category =  TypeCategory::Integral;}

		/*template <> struct Type<X> \
{ static const char* name; } ; const char* TypeParseTraits<X>::name = #X*/





		//#define KING_REGISTER_PARSE_TYPE(_Ty) \ Type<_Ty>::registerType(); 




		//template <> char * Type<T>::_name = #Ty;*/
		/*char * Type<Ty>::_name = #Ty; \*/



		// register default types
		//
		//KING_REGISTER_PARSE_TYPE(unsigned int)
		//KING_REGISTER_PARSE_TYPE(bool)
		//KING_REGISTER_PARSE_TYPE(double)
		//KING_REGISTER_PARSE_TYPE(float)


		// in c-file
		//#define KING_REGISTER_PARSE_TYPE(X) \
				    //template <> char * Type<X>::_name = #X


		//: _Cat_base<__is_class(_Ty)>








		/*template<typename T>
		struct TypeParseTraits;

		#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
		{ static const char* name; } ; const char* TypeParseTraits<X>::name = #X


		REGISTER_PARSE_TYPE(int);
		REGISTER_PARSE_TYPE(double);*/

		/*template<typename T>
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

		return tname;


		}



	};




	}

	
}*/

/*#define KING_REGISTER_TYPE_SET_CATEGORY(X) \
( \
	( if (std::is_class<X>()) return king::system::TypeCategory::Class  ), \
	(king::system::TypeCategory)0 \
)*/

/*#define KING_REGISTER_TYPE(X) \
template <> \
char * king::system::Type<X>::_name = #X; */


//king::system::TypeCategory king::system::Type<X>::_category = KING_REGISTER_TYPE_SET_CATEGORY(X)

#endif