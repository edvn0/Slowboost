//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Negative.hpp"

Negative::Negative(SharedNodePtr value)
	: Operation(std::move(value), {}, "Negative"){};

SharedNodePtr Negative::execute()
{
	auto matrix = left->get_output();

	return std::make_unique<Variable>(-matrix);
}

std::array<Matrix, 2> Negative::backprop(const Matrix& wrt) { return { -wrt, {} }; }