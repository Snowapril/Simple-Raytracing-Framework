#pragma once

//! Check SSE4.2, AVX register support
#if defined( _MSV_VER ) && _MSC_VER >= 1600 //! MSVC compiler and above visual studio 2010
    #ifdef defined (  __AVX__  ) && ( ( defined( _M_AMD64 ) || defined( _M_X64 ) ) || _M_IX86_FP == 2 )
    #define GM_SIMD_SUPPORT 1
    #endif
#elif defined( __GNUC__ ) && ( __GNUC___ > 6 || ( __GNUC__ == 6 && __GNUC_MINOR__ >= 0 ) ) //! GCC compiler and version 6.0 or higher
    #ifdef __SSE2 // && __AVX__
    #define GM_SIMD_SUPPORT 1
    #endif
#elif defined( __clang__ ) && ( __clang_major__ > 5 || ( __clang_major__ == 5 && __clang_minor__ >= 0 ) ) //! clang compiler and version 5.0 or higher.
    #ifdef __SSE2
    #define GM_SIMD_SUPPORT 1
    #endif
#endif

/**
* gcc -mavx2 -dM -E - < /dev/null | egrep "SSE|AVX" | sort
* above command print all macros in my environment.
* In my aws cloud9 environment. 
* #define __SSE2_MATH__ 1
* #define __SSE2__ 1
* #define __SSE3__ 1
* #define __SSE_MATH__ 1
* #define __SSE__ 1
**/