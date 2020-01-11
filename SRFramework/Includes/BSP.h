#pragma once

#include <vector>
#include <gm/vector.h>

#include "Polygon.h"

namespace srf
{
    template <typename Polygon>
    class BSP
    {
    public:
        using polygon_type = typename Polygon;

        class Node
        {
        public:
            using value_type    = typename polygon_type;
            using pointer_type  = Node*;

            ~Node();
        public:
            pointer_type posNode;
            pointer_type negNode;
            Polygon splitPlane;
            std::vector<Polygon> polygons;
        };
        using node_type = Node;
    public:
        BSP() = default;
        template <typename Container>
        BSP(Container<Polygon>&& polygons, int depthLimit)
        {

        }
        ~BSP()
        {

        }
        void insert(polygon_type polygon) noexcept
        {
            
        }
        template <typename Container>
        void insert(Container<Polygon>&& polygons) noexcept
        {
            
        }
        void setDepthLimit(int limit) noexcept
        {
            this->depthLimit = limit;
        }
    private:
        node_type* root;
        int depthLimit = 100;
    };
};