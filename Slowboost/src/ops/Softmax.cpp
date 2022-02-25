//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Softmax.hpp"

#include <iostream>

Softmax::Softmax(SharedNodePtr value)
	: Operation(std::move(value), {}, "Softmax"){};

SharedNodePtr Softmax::execute()
{
	auto l = left->get_output();

	Matrix max = xt::amax(l, { 0, 1 });
	Matrix e_x = xt::exp(l - max.reshape({ -1, 1 }));
	Matrix sum = xt::sum(e_x, { 1 });
	Matrix out = e_x / sum;

	return std::make_unique<Variable>(out);
}

std::array<Matrix, 2> Softmax::backprop(const Matrix& wrt) { return {}; }
