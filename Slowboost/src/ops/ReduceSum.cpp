//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/ReduceSum.hpp"

#include <iostream>

ReduceSum::ReduceSum(SharedNodePtr value, int axis)
	: Operation(std::move(value), {}, "ReduceSum")
	, axis(axis)
{
}

SharedNodePtr ReduceSum::execute()
{
	auto matrix = left->get_output();
	Matrix out;
	if (axis == 0) {
		out = matrix.colwise().sum();
	} else if (axis == 1) {
		out = matrix.rowwise().sum();
	} else {
		throw std::runtime_error("Only rows and columns accepted.");
	}

	return std::make_unique<Variable>(out);
}

Matrix ReduceSum::differentiate() { return left->get_output(); }
