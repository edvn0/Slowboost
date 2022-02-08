//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_COMMON_HPP
#define COMP_GRAPH_COMMON_HPP

#include "Operation.hpp"
#include "Placeholder.hpp"
#include "Variable.hpp"
#include "types.hpp"

#include <iostream>
#include <utility>

auto var(Eigen::MatrixXd&& val) -> SharedNodePtr { return std::make_shared<Variable>(val); }

auto var(const Eigen::MatrixXd& val) -> SharedNodePtr { return std::make_shared<Variable>(val); }

auto ph(const std::string& name) -> SharedNodePtr { return std::make_shared<Placeholder>(name); };

template <typename T = Operation, typename... Args> auto op(Args&&... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}

#ifdef CG_DEBUG
#define DEBUG(x) std::cout << "\n" << (x) << "\n"
#else
#define DEBUG
#endif

#endif // COMP_GRAPH_COMMON_HPP