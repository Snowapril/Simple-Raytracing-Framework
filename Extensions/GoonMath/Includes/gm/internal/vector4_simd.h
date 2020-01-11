/**
 * @file vector4_simd.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief vector4 class implemented with simd register
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

//! SIMD tutorial
//! http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf
#pragma once

#include <stdalign.h>
#include "gm/util.h"
#include "gm/internal/vector4.h"

#ifdef GM_SIMD_SUPPORT
#include "gm/simd/simd4f.h"
#endif

namespace gm
{
    #ifdef GM_SIMD_SUPPORT
    template <>
    class vector<float, 4> 
    {
    public:
        using value_type = float;
        using size_type  = int;
        
        //! brief : initialize data as uninitialized array.
        vector(  ) = default;
        
        inline vector( vector<float, 4> const& v )
        {
            this->simd4 = v.simd4;
        }
        template <typename U>
        inline vector( vector<U, 4> const& v )
        {
            this->simd4 = simd4f( 
                static_cast<value_type>(v.x),  
                static_cast<value_type>(v.y),
                static_cast<value_type>(v.z),
                static_cast<value_type>(v.w)
            );
        }
        inline vector( simd4f s4 )
        {
            this->simd4 = s4;
        }
        inline vector( float e1 )
        {
            this->simd4 = simd4f( e1 );
        }
        inline vector( float *elements )
        {
            this->simd4 = simd4f( elements );
        }
        inline vector( float x, float  y, float z, float w )
        {
            this->simd4 = simd4f( x, y, z, w );
        }
        
        inline value_type& operator[]( int i ) { return data[i]; };
        inline value_type const& operator[]( int i ) const { return data[i]; };
    public:
        union
        {
            simd4f simd4;
            alignas( 16 ) float data[4];
            struct 
            {
                alignas( 16 ) float x, y, z, w;
            };
        };
    };
    
    //! operator overloading related to vector class below.
    inline bool operator==( vector<float, 4> const& v1, vector<float, 4> const& v2 )
    {
        return v1.simd4 == v2.simd4;
    }
    inline bool operator!=( vector<float, 4> const& v1, vector<float, 4> const& v2 )
    {
        return !( v1 == v2 );
    }
    inline vector<float, 4> operator-( vector<float, 4> const& v )
    {
        return vector<float, 4>( -v.simd4 );
    }
    inline vector<float, 4> operator+( vector<float, 4> const& v1, vector<float, 4> const& v2 )
    {
        return vector<float, 4>( v1.simd4 + v2.simd4 );
    }
    inline vector<float, 4> operator-( vector<Tfloat, 4> const& v1, vector<float, 4> const& v2 )
    {
        return vector<float, 4>( v1.simd4 - v2.simd4 );
    }
    inline vector<float, 4> operator*( vector<float, 4> const& v1, vector<float, 4> const& v2 )
    {
        return vector<float, 4>( v1.simd4 * v2.simd4 );
    }
    inline vector<float, 4> operator/( vector<float, 4> const& v1, vector<float, 4> const& v2 )
    {
        return vector<float, 4>( v1.simd4 / v2.simd4 );
    }
    inline vector<float, 4>& operator+=( vector<float, 4>& v1, vector<float, 4> const& v2 )
    {
        v1.simd4 += v2.simd4;
        return v1;
    }
    inline vector<float, 4>& operator-=( vector<float, 4>& v1, vector<float, 4> const& v2 )
    {
        v1.simd4 -= v2.simd4;
        return v1;
    }
    inline vector<float, 4>& operator*=( vector<float, 4>& v1, vector<float, 4> const& v2 )
    {
        v1.simd4 *= v2.simd4;
        return v1;
    }
    inline vector<float, 4>& operator/=( vector<float, 4>& v1, vector<float, 4> const& v2 )
    {
        v1.simd4 /= v2.simd4;
        return v1;
    }
    inline vector<float, 4> operator+( float s, vector<float, 4> const& v )
    {
        vector<float, 4> result;
        for ( int i = 0; i < 4; ++i ) 
            result.data[i] = v1.data[i] + s;
        return result;
    }
    inline vector<float, 4> operator-( float s, vector<float, 4> const& v )
    {
        vector<float, 4> result;
        for ( int i = 0; i < 4; ++i ) 
            result.data[i] = v1.data[i] - s;
        return result;
    }
    inline vector<float, 4> operator*( float s, vector<float, 4> const& v )
    {
        vector<float, 4> result;
        for ( int i = 0; i < 4; ++i ) 
            result.data[i] = v1.data[i] * s;
        return result;
    }
    inline vector<float, 4> operator/( float s, vector<float, 4> const& v )
    {
        vector<float, 4> result;
        for ( int i = 0; i < 4; ++i ) 
            result.data[i] = v1.data[i] / s;
        return result;
    }
    inline vector<float, 4>& operator+=( vector<float, 4>& v, float s )
    {
        for ( int i = 0; i < 4; ++i )
            v1.data[i] += s;
        return v1;
    }
    inline vector<float, 4>& operator-=( vector<float, 4>& v, float s )
    {
        for ( int i = 0; i < 4; ++i )
            v1.data[i] -= s;
        return v1;
    }
    inline vector<float, 4>& operator*=( vector<float, 4>& v, float s )
    {
        for ( int i = 0; i < 4; ++i )
            v1.data[i] *= s;
        return v1;
    }
    inline vector<float, 4>& operator/=( vector<float, 4>& v, float s )
    {
        for ( int i = 0; i < 4; ++i )
            v1.data[i] /= s;
        return v1;
    }
    #endif
};