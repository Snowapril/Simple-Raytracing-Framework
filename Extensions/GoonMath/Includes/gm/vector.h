#pragma once

//! http://egloos.zum.com/himskim/v/3630181

#include <cmath>
#include <type_traits>
#include <iterator>

namespace gm 
{
    template <typename T, int Dims>
    class vector 
    {
    public:
        using value_type             = T;
        using size_type              = int;
        using iterator               = value_type*;
        using const_iterator         = value_type const*;
        using reverse_iterator       = std::reverse_iterator< iterator >;
        using const_reverse_iterator = std::reverse_iterator< const_iterator >;
        
        //! brief : initialize data as uninitialized array.
        vector(  ) = default;
        
        vector( vector<T, Dims> const& v )
        {
            for ( int i = 0; i < Dims; ++i ) 
                this->data[i] = v.data[i];
        }
        template <typename U>
        vector( vector<U, Dims> const& v )
        {
            for ( int i = 0; i < Dims; ++i )
                this->data[i] = static_cast<T>( v.data[i] );
        }
        vector( T e1 )
        {
            for ( int i = 0; i < Dims; ++i )
                this->data[i] = e1;
        }
        vector( T *elements )
        {
            for ( int i = 0; i < Dims; ++i )
                this->data[i] = elements[i];
        }
        vector( T x, T y )
        {
            static_assert( Dims == 2 );
            this->data[0] = x;
            this->data[1] = y;
        }
        vector( T x, T y, T z )
        {
            static_assert( Dims == 3 );
            this->data[0] = x;
            this->data[1] = y;
            this->data[2] = z;
        }
        vector( T x, T y, T z, T w )
        {
            static_assert( Dims == 4 );
            this->data[0] = x;
            this->data[1] = y;
            this->data[2] = z;
            this->data[3] = w;
        }
        
        inline value_type& operator[]( int i ) { return data[i]; };
        inline value_type const& operator[]( int i ) const { return data[i]; };
        
        iterator begin()
        {
            return data;
        }
        iterator end()
        {
            return data + Dims;
        }
        const_iterator cbegin() const
        {
            return data;
        }
        const_iterator cend() const
        {
            return data + Dims;
        }
        reverse_iterator rbegin()
        {
            return data + Dims - 1;
        }
        reverse_iterator rend()
        {
            return data - 1;
        }
        const_reverse_iterator rbegin() const
        {
            return data + Dims - 1;
        }
        const_reverse_iterator rend() const
        {
            return data - 1;
        }
    public:
        value_type data[Dims];
    };
    
    //! operator overloading related to vector class below.
    template <typename T, typename U, int Dims>
    inline bool operator==( vector<T, Dims> const& v1, vector<U, Dims> const& v2 )
    {
        for ( int i = 0; i < Dims; ++i ) 
            if ( v1[i] != v2[i] ) return false;
        return true;
    }
    template <typename T, typename U, int Dims>
    inline bool operator!=( vector<T, Dims> const& v1, vector<U, Dims> const& v2 )
    {
        return !( v1 == v2 );
    }
    template <typename T, int Dims>
    inline vector<T, Dims> operator-( vector<T, Dims> const& v )
    {
        vector<T, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = -v.data[i];
        return result;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator+( vector<T, Dims> const& v1, vector<U, Dims> const& v2 )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v1.data[i] + v2.data[i]);
        return result;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator-( vector<T, Dims> const& v1, vector<U, Dims> const& v2 )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v1.data[i] - v2.data[i]);
        return result;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator*( vector<T, Dims> const& v1, vector<U, Dims> const& v2 )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v1.data[i] * v2.data[i]);
        return result;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator/( vector<T, Dims> const& v1, vector<U, Dims> const& v2 )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v1.data[i] / v2.data[i]);
        return result;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator+=( vector<T, Dims>& v1, vector<U, Dims> const& v2 )
    {
        for ( int i = 0; i < Dims; ++i )
            v1.data[i] += static_cast<T>(v2.data[i]);
        return v1;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator-=( vector<T, Dims>& v1, vector<U, Dims> const& v2 )
    {
        for ( int i = 0; i < Dims; ++i )
            v1.data[i] -= static_cast<T>(v2.data[i]);
        return v1;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator*=( vector<T, Dims>& v1, vector<U, Dims> const& v2 )
    {
        for ( int i = 0; i < Dims; ++i )
            v1.data[i] *= static_cast<T>(v2.data[i]);
        return v1;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator/=( vector<T, Dims>& v1, vector<U, Dims> const& v2 )
    {
        for ( int i = 0; i < Dims; ++i )
            v1.data[i] /= static_cast<T>(v2.data[i]);
        return v1;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator+( vector<T, Dims> const& v, U const& s )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v.data[i] + s);
        return result;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator-( vector<T, Dims> const& v, U const& s )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v.data[i] - s);
        return result;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator*( vector<T, Dims> const& v, U const& s )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v.data[i] * s);
        return result;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    inline vector<CommonType, Dims> operator/( vector<T, Dims> const& v, U const& s )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i ) 
            result.data[i] = static_cast<CommonType>(v.data[i] / s);
        return result;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator+=( vector<T, Dims>& v, U const& s )
    {
        for ( int i = 0; i < Dims; ++i )
            v.data[i] += static_cast<T>(s);
        return v;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator-=( vector<T, Dims>& v, U const& s )
    {
        for ( int i = 0; i < Dims; ++i )
            v.data[i] -= static_cast<T>(s);
        return v;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator*=( vector<T, Dims>& v, U const& s )
    {
        for ( int i = 0; i < Dims; ++i )
            v.data[i] *= static_cast<T>(s);
        return v;
    }
    template <typename T, typename U, int Dims>
    inline vector<T, Dims>& operator/=( vector<T, Dims>& v, U const& s )
    {
        for ( int i = 0; i < Dims; ++i )
            v.data[i] /= static_cast<T>(s);
        return v;
    }
    
    //! vector related function declarations here.
    template <typename T, int Dims>
    double length( vector<T, Dims> const& v )
    {
        T sum = T( 0 );
        for ( int i = 0; i < Dims; ++i )
            sum += v.data[i] * v.data[i];
        return std::sqrt( sum );
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    CommonType dot( vector<T, Dims> const& v1, vector<U, Dims> const& v2 )
    {
        CommonType result = CommonType( 0 );
        for ( int i = 0; i < Dims; ++i )
            result += static_cast<CommonType>(v1.data[i] * v2.data[i]);
        return result;
    }
    template <typename T, int Dims>
    T sum( vector<T, Dims> const& v )
    {
        T sum = T( 0 );
        for ( int i = 0; i < Dims; ++i )
            sum += v.data[i];
        return sum;
    }
    template <typename T, typename U, int Dims, typename CommonType = typename std::common_type<T, U>::type>
    vector<CommonType, Dims> lerp( vector<T, Dims> const& v1, vector<U, Dims> const& v2, float t )
    {
        vector<CommonType, Dims> result;
        for ( int i = 0; i < Dims; ++i )
            result.data[i] = static_cast<CommonType>(v1.data[i] * t + v2.data[i] * ( 1.0f - t ));
        return result;
    }
    template <typename T, int Dims>
    vector<T, Dims> clamp( vector<T, Dims> const& v, float min, float max )
    {
        vector<T, Dims> result;
        for ( int i = 0; i < Dims; ++i )
            if ( v.data[i] < min ) 
                result.data[i] = min;
            else if ( v.data[i] > max ) 
                result.data[i] = max;
            else
                result.data[i] = v.data[i];
        return result;
    }
    template <typename T, int Dims>
    vector<T, Dims> saturate( vector<T, Dims> const& v )
    {
        return clamp( v, 0.0f, 1.0f );
    }
};

#include "gm/internal/vector2_simd.h"
#include "gm/internal/vector3_simd.h"
#include "gm/internal/vector4_simd.h"

#include "gm/internal/aliasing.h"