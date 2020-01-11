#pragma once


#include "gm/vector.h"

namespace gm
{
    template <typename T>
    class vector<T, 2> 
    {
    public:
        using value_type = T;
        using size_type  = int;
        
        //! brief : initialize data as uninitialized array.
        vector(  ) = default;
        
        inline vector( vector<T, 2> const& v )
        {
            this->x = v.x;
            this->y = v.y;
        }
        template <typename U>
        inline vector( vector<U, 2> const& v )
        {
            this->x = static_cast<value_type>( v.x );
            this->y = static_cast<value_type>( v.y );
        }
        vector( T e1 )
        {
            this->x = e1;
            this->y = e1;
        }
        vector( T *elements )
        {
            this->x = elements[0];
            this->y = elements[1];
        }
        vector( T x, T y )
        {
            this->x = x;
            this->y = y;
        }
        
        inline value_type& operator[]( int i ) { return data[i]; };
        inline value_type const& operator[]( int i ) const { return data[i]; };
    public:
        union
        {
            value_type data[2];
            struct 
            {
                value_type x, y;
            };
        };
    };
};