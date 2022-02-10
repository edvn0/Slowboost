//
// Created by Edwin Carlsson on 2022-02-09.
//

#ifndef SLOWBOOSTALL_GRADIENTS_HPP
#define SLOWBOOSTALL_GRADIENTS_HPP

#include "Node.hpp"
#include <queue>
#include <set>
#include <unordered_map>

struct OptimizerParameters {
	enum class Optimizer { Adam, GradientDescent, Momentum };

	double learning = 0.01;
	double momentum = 0.01;
	double adam_alpha = 0.01;
	double adam_beta = 0.01;

	Optimizer optimizer = Optimizer::GradientDescent;
};

using GradTable = std::unordered_map<Node*, Matrix>;
using GradQueue = std::queue<SharedNodePtr>;
using GradSet = std::set<SharedNodePtr>;

GradTable compute_gradients(const SharedNodePtr& loss);

SharedNodePtr minimize(const SharedNodePtr& loss_node, const OptimizerParameters& parameters = {});

#endif // SLOWBOOSTALL_GRADIENTS_HPP
