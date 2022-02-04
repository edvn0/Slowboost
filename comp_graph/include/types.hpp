//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_TYPES_HPP
#define COMP_GRAPH_TYPES_HPP

#include <eigen3/Eigen/Core>
#include <memory>

class Node;
using NodePtr = std::unique_ptr<Node>;
using SharedNodePtr = std::shared_ptr<Node>;
using Matrix = Eigen::MatrixXd;
using Vector = Eigen::VectorXd;
using MatrixPtr = Eigen::MatrixXd*;

#endif // COMP_GRAPH_TYPES_HPP
