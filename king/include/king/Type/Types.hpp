

#ifndef   KING_TYPES_HPP
#define   KING_TYPES_HPP

////////////////////////////////////////////////////////////
// Define portable fixed-size types
////////////////////////////////////////////////////////////

namespace king
{
	// All "common" platforms use the same size for char, short and int
	// (basically there are 3 types for 3 sizes, so no other match is possible),
	// we can use them without doing any kind of check

	// 8 bits integer types
	typedef signed   char int8;
	typedef unsigned char uint8;

	// 16 bits integer types
	typedef signed   short int16;
	typedef unsigned short uint16;

	// 32 bits integer types
	typedef signed   int int32;
	typedef unsigned int uint32;

	// 64 bits integer types
#if defined(_MSC_VER)
	typedef signed   __int64 int64;
	typedef unsigned __int64 uint64;
#else
	typedef signed   long long int64;
	typedef unsigned long long uint64;
#endif





} // namespace king

#endif