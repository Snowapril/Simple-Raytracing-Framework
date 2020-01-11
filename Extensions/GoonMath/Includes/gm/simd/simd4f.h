/**
 * @file simd4f.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief simd register wrapper class.
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

//! http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf
//! https://www.univ-orleans.fr/lifo/Members/Sylvain.Jubertie/doc/SIMD/html/group___s_s_esetops.html
#include <nmmintrin.h> // for SSE4.2
#include <immintrin.h> // for AVX 

namespace gm
{
    class simd4f
    {
    public:
        simd4f(  )
        {
            this->simd_data = _mm_setzero_ps(  );
        }
        simd4f( float x, float y, float z, float w=0.0f )
        {
            this->simd_data = _mm_set_ps( x, y, z, w );
        }
        simd4f( float element )
        {
            this->simd_data = _mm_set1_ps( element );
        }
        simd4f( float *elements )
        {
            this->simd_data = _mm_set_ps(elements[0], elements[1], 
                                         elements[2], elements[3]);
        }
        simd4f( simd4f const& s ) noexcept
        {
            this->simd_data = s.simd_data;
        }
    public:
        __m128 simd_data;
    };
    
    //! operator overloading related to vector class below.
    inline bool operator==( simd4f const& v1, simd4f const& v2 )
    {
        __m128 eq_mask = _mm_cmpeq_ps( v1.simd_data, v2.simd_data );
        int result = _mm_movemask_ps( eq_mask );
        
        return ( result & 1 ) && ( result & 2 ) && ( result & 4 ) && ( result & 8 );
    }
    inline bool operator!=( simd4f const& v1, simd4f const& v2 )
    {
        return !( v1 == v2 );
    }
    inline simd4f operator-( simd4f const& v )
    {
        simd4f result;
        result.simd_data = _mm_mul_ps( v.simd_data, _mm_set1_ps( -1.0f ) );
        return result;
    }
    inline simd4f operator+( simd4f const& v1, simd4f const& v2 )
    {
        simd4f result;
        result.simd_data = _mm_add_ps( v1.simd_data, v2.simd_data );
        return result;
    }
    inline simd4f operator-( simd4f const& v1, simd4f const& v2 )
    {
        simd4f result;
        result.simd_data = _mm_sub_ps( v1.simd_data, v2.simd_data );
        return result;
    }
    inline simd4f operator*( simd4f const& v1, simd4f const& v2 )
    {
        simd4f result;
        result.simd_data = _mm_mul_ps( v1.simd_data, v2.simd_data );
        return result;
    }
    inline simd4f operator/( simd4f const& v1, simd4f const& v2 )
    {
        simd4f result;
        result.simd_data = _mm_div_ps( v1.simd_data, v2.simd_data );
        return result;
    }
    inline simd4f& operator+=( simd4f& v1, simd4f const& v2 )
    {
        v1.simd_data = _mm_add_ps( v1.simd_data, v2.simd_data );
        return v1;
    }
    inline simd4f& operator-=( simd4f& v1, simd4f const& v2 )
    {
        v1.simd_data = _mm_sub_ps( v1.simd_data, v2.simd_data );
        return v1;
    }
    inline simd4f& operator*=( simd4f& v1, simd4f const& v2 )
    {
        v1.simd_data = _mm_mul_ps( v1.simd_data, v2.simd_data );
        return v1;
    }
    inline simd4f& operator/=( simd4f& v1, simd4f const& v2 )
    {
        v1.simd_data = _mm_div_ps( v1.simd_data, v2.simd_data );
        return v1;
    }
    inline simd4f operator+( float s, simd4f const& v )
    {
        simd4f result;
        result.simd_data = _mm_add_ps( _mm_set1_ps(s), v.simd_data );
        return result;
    }
    inline simd4f operator-( float s, simd4f const& v )
    {
        simd4f result;
        result.simd_data = _mm_sub_ps( _mm_set1_ps(s), v.simd_data );
        return result;
    }
    inline simd4f operator*( float s, simd4f const& v )
    {
        simd4f result;
        result.simd_data = _mm_mul_ps( _mm_set1_ps(s), v.simd_data );
        return result;
    }
    inline simd4f operator/( float s, simd4f const& v )
    {
        simd4f result;
        result.simd_data = _mm_div_ps( _mm_set1_ps(s), v.simd_data );
        return result;
    }
    inline simd4f& operator+=( simd4f& v, float s )
    {
        v.simd_data = _mm_add_ps( v.simd_data, _mm_set1_ps(s) );
        return v;
    }
    inline simd4f& operator-=( simd4f& v, float s )
    {
        v.simd_data = _mm_sub_ps( v.simd_data, _mm_set1_ps(s) );
        return v;
    }
    inline simd4f& operator*=( simd4f& v, float s )
    {
        v.simd_data = _mm_mul_ps( v.simd_data, _mm_set1_ps(s) );
        return v;
    }
    inline simd4f& operator/=( simd4f& v, float s )
    {
        v.simd_data = _mm_div_ps( v.simd_data, _mm_set1_ps(s) );
        return v;
    }
    
    typedef union {
        simd4f s;
        struct 
        {
            float x, y, z, w;
        };
    } simd4f_union;
    
    inline float simd4f_get_x( simd4f s ) { simd4f_union u={s}; return u.x; }
    inline float simd4f_get_y( simd4f s ) { simd4f_union u={s}; return u.y; }
    inline float simd4f_get_z( simd4f s ) { simd4f_union u={s}; return u.z; }
    inline float simd4f_get_w( simd4f s ) { simd4f_union u={s}; return u.w; }
};