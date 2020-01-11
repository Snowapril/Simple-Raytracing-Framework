#pragma once

#include <cassert>
#include <gm/vector.h>
#include <type_traits>

namespace srf
{
    template < 
                typename Type, int Dims, int NumVertices, 
                typename = typename std::enable_if<(Dims <= 4) && (Dims >= 2), void>::type 
             >
    class Polygon
    {
    public:
        using vertex_type   = gm::vector<Type, Dims>;
        using polygon       = Polygon<Type, Dims, NumVertices>;

        template <typename _Type>
        Polygon(Polygon<_Type, Dims, NumVertices> const& p)
        {
            for (int i = 0; i < Dims; ++i)
                vertices[i] = static_cast<Type>(p.vertices[i]);
        }
        template <typename _Type>
        polygon& operator=(Polygon<_Type, Dims, NumVertices> const& p) 
        {
            if (this != &p)
            {
                for (int i = 0; i < Dims; ++i)
                    vertices[i] = static_cast<Type>(p.vertices[i]);
            }
            return *this;
        }
        vertex_type& operator[](int index) 
        {
            assert(index >= 0 && index < NumVertices);
            return vertices[index];
        }
        vertex_type const& operator[](int index) const
        {
            assert(index >= 0 && index < NumVertices);
            return vertices[index];
        }
        virtual vertex_type getNormal() const noexcept = 0;
        virtual void split(polygon splitPolygon, polygon& pos, polygon& neg) noexcept = 0;
    public:
        vertex_type vertices[NumVertices];
    };

    template < typename Type, int Dims >
    class Line : public Polygon<Type, Dims, 2>
    {
    public:
        Line(vertex_type v1, vertex_type v2) noexcept
            : vertices { v1, v2 } { };
        
        vertex_type getNormal() const noexcept override
        {
            
        }
        void split(polygon splitPolygon, polygon& pos, polygon& neg) noexcept override
        {

        }
    };

    template < typename Type, int Dims >
    class Triangle : public Polygon<Type, Dims, 3>
    {
    public:
        Triangle(vertex_type v1, vertex_type v2, vertex_type v3) noexcept
            : vertices { v1, v2, v3 } { };

        vertex_type getNormal() const noexcept override
        {
            
        }
        void split(polygon splitPolygon, polygon& pos, polygon& neg) noexcept override
        {

        }
    };
};