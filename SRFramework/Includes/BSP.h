/**
 * @file BSP.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief Binary Space Partitioning tree for scene traversing.
 * @date 2020-01-13
 * 
 * @copyright Copyright (c) 2019 snowapril
 * This code is licensed under MIT License (see LICENSE for details)
 * 
 */
#pragma once
//! https://web.cs.wpi.edu/~matt/courses/cs563/talks/bsp/document.html

#include <vector>
#include <gm/vector.h>

#include "Polygon.h"

namespace srf
{
    template <typename Polygon>
    class BSP
    {
    public:
        using polygon_type = Polygon;
        using vertex_type = Polygon::vertex_type;

        class Node
        {
            friend class BSP<Polygon>;
        public:
            using polygon_type  = BSP::polygon_type;
            using vertex_type   = BSP::vertex_type;
            using pointer_type  = Node*;

            Node(polygon_type poly)
                : polygons { poly }
            {
                splitPlane = poly.getNormal();
            }
            ~Node()
            {
                if (posNode) delete posNode;
                if (negNode) delete negNode;
            }
        private:
            pointer_type posNode;
            pointer_type negNode;
            BSP::vertex_type splitPlane;
            std::vector<polygon_type> polygons;
        };
        using node_type = Node;
    public:
        /**
         * @param  depthLimit - limit for tree depth (or height).
         */ 
        BSP(int depthLimit) : depthLimit(depthLimit) {};
        /**
         * @tparam Container - container type which has polygons as it's data. 
         *                     This container type must support range-based for loop.
         * @param  polygons - polygons for building BSP tree.
         * @param  depthLimit - limit for tree depth (or height).
         */
        template <typename Container>
        BSP(Container&& polygons, int depthLimit)
            : BSP(depthLimit)
        {
            insert(std::forward<Container>(polygons));
        }
        ~BSP()
        {
            if (root)
            {
                delete root;
            }
        }
        
        template <typename Container>
        void insert(Container&& polygons) noexcept
        {
            auto container = std::forward<Container>(polygons);
            node_type* temp_node;
            polygon_type temp_poly;
            int temp_depth;

            //! auto rootPoly = container.randPop();
            //! this->root = new node_type(rootPoly);

            for (auto const& polygon : container)
            {
                //! stack<std::tuple<node_type*, polygon_type, int>> bspstack;
                //! std::tie(temp_node, temp_poly, temp_depth) = bspstack.top();
                //! check polygon whether if splitted by root partition plane or not.
                //! 1. no split. positive side. -> go left node
                //! 2. no split. negative side. -> go right node
                //! 3. no split. coincide with root plane. -> push_back to root node vector.
                //! 4. splitted. split polygon into two or more polygons and go left and right.
            }
        }
        void setDepthLimit(int limit) noexcept
        {
            this->depthLimit = limit;
        }
    private:
        node_type* root = nullptr;
        int depthLimit = 100;
    };
};