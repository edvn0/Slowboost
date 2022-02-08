//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_TYPES_HPP
#define COMP_GRAPH_TYPES_HPP

#include <eigen3/Eigen/Core>
#include <memory>

class Node;
using SharedNodePtr = std::shared_ptr<Node>;

typedef Eigen::Vector<double, Eigen::Dynamic> Vector;
typedef Eigen::RowVector<double, Eigen::Dynamic> RowVector;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Matrix;
typedef Eigen::Array<double, Eigen::Dynamic, Eigen::Dynamic> Array;

#endif // COMP_GRAPH_TYPES_HPP
