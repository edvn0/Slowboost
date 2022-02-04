//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_COMMON_HPP
#define COMP_GRAPH_COMMON_HPP

#include "Operation.hpp"
#include "Variable.hpp"
#include "Placeholder.hpp"
#include "types.hpp"

auto var(Eigen::MatrixXd&& val) -> NodePtr { return std::make_unique<Variable>(val); }

auto var(const Eigen::MatrixXd& val) -> NodePtr { return std::make_unique<Variable>(val); }

auto ph(const std::string& name) -> NodePtr { return std::make_unique<Placeholder>(name); };

template <typename T = Operation> auto op(NodePtr left, NodePtr right) -> NodePtr
{
	return std::make_unique<T>(std::move(left), std::move(right));
}

template <typename T = Operation> auto op(NodePtr node) -> NodePtr
{
	return std::make_unique<T>(std::move(node));
}


#endif // COMP_GRAPH_COMMON_HPP