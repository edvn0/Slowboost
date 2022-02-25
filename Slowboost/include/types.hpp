//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_TYPES_HPP
#define COMP_GRAPH_TYPES_HPP

#include <memory>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

class Node;
using SharedNodePtr = std::shared_ptr<Node>;

using Matrix = xt::xarray<double>;
using Array = xt::xarray<double>;

#endif // COMP_GRAPH_TYPES_HPP
