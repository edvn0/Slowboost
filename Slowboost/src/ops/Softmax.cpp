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
	auto max_along_row = xt::amax(l, { 1 });

	INFO("{}", max_along_row);

	auto e_x = xt::exp(l - max_along_row);
	auto out = e_x / xt::sum(l);

	INFO("Softmax Shape: {} x {}", out.shape(0), out.shape(1));

	return std::make_unique<Variable>(out);
}

std::array<Matrix, 2> Softmax::backprop(const Matrix& wrt) { return {}; }
