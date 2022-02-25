//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Tanh.hpp"

Tanh::Tanh(SharedNodePtr value)
	: Operation(std::move(value), {}, "Tanh"){};

SharedNodePtr Tanh::execute()
{
	auto matrix = left->get_output();

	return std::make_unique<Variable>(xt::tanh(matrix));
}

std::array<Matrix, 2> Tanh::backprop(double wrt) { return { wrt * output * (1 - output * output), {} }; }
