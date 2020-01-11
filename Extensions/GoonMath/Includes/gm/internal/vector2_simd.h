/**
 * @file vector2_simd.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief vector2 class implemented with simd register
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

#include "gm/internal/vector2.h"
#include "gm/util.h"

#ifdef GM_SIMD_SUPPORT
#include "gm/simd/simd2f.h"
#endif

namespace gm
{
    /**
    #ifdef GM_SIMD_SUPPORT
    template <>
    class vector<float, 2> 
    {
    public:
        
    public:
        union
        {
            simd2f simd2;
            alignas( 8 ) float data[2];
            struct 
            {
                alignas( 8 ) float x, y;
            };
        };
    };
    #endif
    */
};