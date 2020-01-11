#pragma once

//! LLDB commands cheat sheet : https://lldb.llvm.org/use/map.html

#include "gm/vector.h"
#include "gm/bitwise.h"
#include <limits>

namespace gm
{
    /**
	 * @brief return whether if given three vertices compose triangle or not.
	 * @details if any of two edge slopes in the triangle equals, then given three vertices cannot compose triangle.
     *          if ( (x1 - x0) / (y1 - y0) == (x2 - x1) / (y2 - y1) ) return false;
     *          Above equation can cause divided by zero error. 
     *          By fraction reduction, we can prevent such a error. Below form is complete answer.
     *          if ( (x1 - x0) * (y2 - y1) == (x2 - x1) * (y1 - y0) ) return false;
     *          else return false;
	 * @tparam Data type of vector elements.
	 * @tparam Vector dimension
	 * @param v0 first vertex that forms the triangle
     * @param v1 second vertex that forms the triangle
     * @param v2 third vertex that forms the triangle
	 * @return true  given three vertices can compose triangle.
	 * @return false given three vertices cannot compose triangle.
	 */
    template <typename Type>
    inline bool checkTriangle(vector<Type, 2> const& v0, vector<Type, 2> const& v1, vector<Type, 2> const& v2) noexcept
    {
        return (v1.x - v0.x) * (v2.y - v1.y) != (v2.x - v1.x) * (v1.y - v0.y);
    }

    template <typename Type>
    vector<float, 3> barycentric(vector<Type, 2> const& point, vector<Type, 2> const& v0, vector<Type, 2> const& v1, vector<Type, 2> const& v2) noexcept
    {
        if ( checkTriangle(v0, v1, v2)  == false )
            return vector<float, 3>(-1.0f, -1.0f, -1.0f);

        Type cy = v2.y - v0.y;
        Type cx = v2.x - v0.x;
        Type by = v1.y - v0.y;
        Type bx = v1.x - v0.x;
        
        float w1 = ( v0.x * cy + (point.y - v0.y) * cx - point.x * cy ) / static_cast<float>(by * cx - bx * cy);
        float w2 = ( point.y - v0.y - w1 * by ) / static_cast<float>(cy);
        
        return vector<float, 3>(w1, w2, 1.0f - w1 - w2);
    }  
};
