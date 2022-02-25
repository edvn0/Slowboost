//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Sigmoid.hpp"

Sigmoid::Sigmoid(SharedNodePtr value)
	: Operation(std::move(value), {}, "Sigmoid"){};

SharedNodePtr Sigmoid::execute()
{
	auto l = left->get_output();
	return std::make_unique<Variable>(1.0 / (1.0 + xt::exp(-l)));
}

std::array<Matrix, 2> Sigmoid::backprop(double wrt) { return {}; }
