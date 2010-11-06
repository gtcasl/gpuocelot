/*! \file MetaProgramming.h
	\date Thursday May 27, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for template meta programming related classes
*/

#ifndef META_PROGRAMMING_H_INCLUDED
#define META_PROGRAMMING_H_INCLUDED

namespace hydrazine
{

/*! \brief Convert a signed type to an unsigned type */
template<typename T>
class SignedToUnsigned
{
	public:
		typedef T type;
};

template<>
class SignedToUnsigned<char>
{
	public:
		typedef unsigned char type;
};

template<>
class SignedToUnsigned<short>
{
	public:
		typedef unsigned short type;
};

template<>
class SignedToUnsigned<int>
{
	public:
		typedef unsigned int type;
};

template<>
class SignedToUnsigned<long long int>
{
	public:
		typedef long long unsigned int type;
};

/*! \brief Determine if an integer type is negative */
template<typename T>
bool isNegative(T t)
{
	return t < 0;
}

inline bool isNegative(unsigned char)
{
	return false;
}

inline bool isNegative(unsigned short)
{
	return false;
}

inline bool isNegative(unsigned int)
{
	return false;
}

inline bool isNegative(long long unsigned int)
{
	return false;
}

}

#endif

