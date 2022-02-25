//
// Created by Edwin Carlsson on 2022-02-09.
//

#include "Gradients.hpp"
#include "common.hpp"
#include "optimizers/GradientDescentOptimizer.hpp"

static Matrix constant(double val) { return xt::xarray<double>({val}); }

GradTable compute_gradients(const SharedNodePtr& loss)
{
	GradTable table;
	table[loss.get()] = constant(1.0);

	GradSet visited;
	GradQueue queue;
	visited.insert(loss);
	queue.push(loss);

	while (!queue.empty()) {
		auto node = queue.front();
		queue.pop();
		auto node_ptr = node.get();

		if (node != loss) {

			table[node_ptr] = constant(0.0);

			auto consumer = node->get_consumer();

			auto lossgrad_wrt_consumer_output = table[consumer];

			auto lossgrads_wrt_consumer_inputs = consumer->backprop(lossgrad_wrt_consumer_output);

			auto children = node->inputs();
            if (children == 0) {
                continue;
            } else if (children == 1) {
                table[node_ptr] += lossgrad_wrt_consumer_output[0];
			} else {
				if (node->get_left()->get_consumer() == node_ptr) {
                    table[node_ptr] += lossgrads_wrt_consumer_inputs[0];
				}

				if (node->get_right()->get_consumer() == node_ptr) {
					table[node_ptr] += lossgrads_wrt_consumer_inputs[0];
				}
			}
		}

		std::array<SharedNodePtr, 2> possible = { node->get_left(), node->get_right() };
		for (auto& p : possible) {
			if (p && !visited.contains(p)) {
				visited.insert(p);
				queue.push(p);
			}
		}
	}
	return table;
};

SharedNodePtr minimize(const SharedNodePtr& loss_node, const OptimizerParameters& parameters)
{
	switch (parameters.optimizer) {
	case OptimizerParameters::Optimizer::Adam:
		throw std::runtime_error("We do not support Adam yet.");
	case OptimizerParameters::Optimizer::GradientDescent:
		return std::make_shared<GradientDescentOptimizer>(loss_node, parameters.learning);
	case OptimizerParameters::Optimizer::Momentum:
		throw std::runtime_error("We do not support Momentum yet.");
	}
};
