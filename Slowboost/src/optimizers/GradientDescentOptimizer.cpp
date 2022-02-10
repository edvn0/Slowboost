//
// Created by Edwin Carlsson on 2022-02-09.
//

#include "optimizers/GradientDescentOptimizer.hpp"
#include "Gradients.hpp"

GradientDescentOptimizer::GradientDescentOptimizer(SharedNodePtr value, double lr)
	: Operation(std::move(value), {}, "GradientDescent")
	, lr(lr){};

SharedNodePtr GradientDescentOptimizer::execute()
{
	auto gradient_map = compute_gradients(left);
	for (auto&& [key, value] : gradient_map) {
		if (key->get_type() == NodeType::VAR) {
			auto* var = dynamic_cast<Variable*>(key);
			var->add_delta(-lr * value);
		}
	}
	return {};
}

Matrix GradientDescentOptimizer::differentiate() { return {}; }

std::array<Matrix, 2> GradientDescentOptimizer::backprop(const Matrix& wrt) { return {}; }
