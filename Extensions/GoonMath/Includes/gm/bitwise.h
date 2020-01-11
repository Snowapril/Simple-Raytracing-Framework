/**
 * @file bitwise.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief several inline functions for bitwise computation.
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include <cstddef>
#include <type_traits>

namespace gm
{
	/****************************************************************************
				Bitwise class declaration
	****************************************************************************/
	class Bitwise
	{
	public:
		/**
		 * @brief return whether if given number is power of two or not.
		 * 
		 * @tparam Type the type of given unsigned number(char, short, int, long, etc..)
		 * @tparam std::enable_if_t< std::is_unsigned_v<Type>> disable this function if given type isn't a unsigned type.
		 * @param num unsigned number which programmer want to check if it is power of two.
		 * @return true  given number is power of two.
		 * @return false given number is not power of two.
		 */
		template <typename Type, typename = typename std::enable_if<std::is_unsigned<Type>::value>::type>
		static bool inline isPO2( Type num )
		{
			return ( num & (num - 1) ) == 0;
		}

		/**
		 * @brief get bitmask with given indices easily
		 * 
		 * \code{.cpp}
		 * unsigned int mask = setBitmask<unsigned int>(0, 3, 7, 9); 
		 * std::cout << std::hex << mask << std::endl; 
		 * >> 0x0289 == 0000001010001001 
		 * \endcode
		 * 
		 * @tparam RetType 
		 * @tparam Bits variadic template parameter for enter the varying number of index.
		 * @tparam std::enable_if_t< std::is_integral_v<RetType>> 
		 * @param bits indices for set mask.
		 * @return std::decay_t<RetType> std::decay_t is used for the cast that programmer enter the return type as reference type by mistake.
		 */
		template < typename RetType, typename... Bits, typename = typename std::enable_if< std::is_integral<RetType>::value>::type>
		static auto inline setBitmask( Bits... bits ) -> std::decay_t<RetType>
		{
			RetType mask = ( (1 << bits) | ... );
			return mask;
		}

        /**
	 	* @brief when any of variadic boolean parameters true, this function will return true.
	 	* 
	 	* @tparam Logics template variadic parameter of variadic boolean parameters.
	 	* @param conditions variadic parameter for several boolean arguments. 
	 	* @return any of boolean parameters is true, return true.
	 	*/
		template < typename... Logics >
		static bool inline anyOf( Logics... conditions )
		{
			return ( (conditions) || ... );
		}

		/**
		 * @brief when any of variadic boolean parameters false, this function will return false.
		 * 
		 * @tparam Logics template variadic parameter of variadic boolean parameters.
		 * @param conditions variadic parameter for several boolean arguments. 
		 * @return any of boolean parameters is false, return false.
		 */
		template < typename... Logics >
		static bool inline allOf( Logics... conditions )
		{
			return ( (conditions) && ... );
		}
	};
};