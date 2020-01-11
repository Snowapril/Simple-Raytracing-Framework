/**
 * @file aliasing.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief aliasing vector related classes
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "gm/vector.h"

namespace gm
{
    //! Type Aliasing here.
    using bvec2 = vector< bool,         2 >;
    using ivec2 = vector< int,          2 >;
    using uvec2 = vector< unsigned int, 2 >;
    using dvec2 = vector< double,       2 >;
    using  vec2 = vector< float,        2 >;
    
    using bvec3 = vector< bool,         3 >;
    using ivec3 = vector< int ,         3 >;
    using uvec3 = vector< unsigned int, 3 >;
    using dvec3 = vector< double,       3 >;
    using  vec3 = vector< float,        3 >;
    
    using bvec4 = vector< bool,         4 >;
    using ivec4 = vector< int,          4 >;
    using uvec4 = vector< unsigned int, 4 >;
    using dvec4 = vector< double,       4 >;
    using  vec4 = vector< float,        4 >;
};