#pragma once


#include "gm/vector.h"

namespace gm
{
    template <typename T>
    class vector<T, 4> 
    {
    public:
        using value_type = T;
        using size_type  = int;
        
        //! brief : initialize data as uninitialized array.
        vector(  ) = default;
        
        inline vector( vector<T, 4> const& v )
        {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            this->w = v.w;
        }
        template <typename U>
        inline vector( vector<U, 4> const& v )
        {
            this->x = static_cast<value_type>( v.x );
            this->y = static_cast<value_type>( v.y );
            this->z = static_cast<value_type>( v.z );
            this->w = static_cast<value_type>( v.w );
        }
        vector( T e1 )
        {
            this->x = e1;
            this->y = e1;
            this->z = e1;
            this->w = e1;
        }
        vector( T *elements )
        {
            this->x = elements[0];
            this->y = elements[1];
            this->z = elements[2];
            this->w = elements[3];
        }
        vector( T x, T y, T z, T w )
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }
        
        inline value_type& operator[]( int i ) { return data[i]; };
        inline value_type const& operator[]( int i ) const { return data[i]; };
    public:
        union
        {
            value_type data[4];
            struct 
            {
                value_type x, y, z, w;
            };
        };
    };
};