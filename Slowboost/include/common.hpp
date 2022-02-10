//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_COMMON_HPP
#define COMP_GRAPH_COMMON_HPP

#include "Operation.hpp"
#include "Placeholder.hpp"
#include "Variable.hpp"
#include "types.hpp"

#include <array>
#include <fstream>
#include <functional>
#include <unordered_map>
#include <utility>
#include <vector>

#ifdef CG_DEBUG
#include <iostream>
#define DEBUG(x) std::cout << "\n" << (x) << "\n"
#else
#define DEBUG
#endif

SharedNodePtr var(Matrix&& val);

SharedNodePtr var(const Matrix& val);

SharedNodePtr ph(const std::string& name);

template <typename T, typename... Args> SharedNodePtr op(Args&&... args)
{
	auto out = std::make_shared<T>(std::forward<Args>(args)...);
	return out;
}

#endif // COMP_GRAPH_COMMON_HPP