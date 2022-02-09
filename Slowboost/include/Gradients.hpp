//
// Created by Edwin Carlsson on 2022-02-09.
//

#ifndef SLOWBOOSTALL_GRADIENTS_HPP
#define SLOWBOOSTALL_GRADIENTS_HPP

#include "Node.hpp"
#include <queue>
#include <set>
#include <unordered_map>

using GradTable = std::unordered_map<SharedNodePtr, double>;
using GradQueue = std::queue<SharedNodePtr>;
using GradSet = std::set<SharedNodePtr>;

GradTable compute_gradients(const SharedNodePtr& loss);

#endif // SLOWBOOSTALL_GRADIENTS_HPP
