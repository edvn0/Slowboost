//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/ReduceSum.hpp"

#include <iostream>

ReduceSum::ReduceSum(SharedNodePtr value, Axis axis)
	: Operation(std::move(value), {}, "ReduceSum")
	, axis(axis)
{
}

SharedNodePtr ReduceSum::execute()
{
	auto matrix = left->get_output();
	Matrix out;
	if (axis == Axis::Zero) {
		out = matrix.colwise().sum();
	} else if (axis == Axis::One) {
		out = matrix.rowwise().sum();
	} else if (axis == Axis::None) {
		auto col = matrix.colwise().sum();
		out = col.rowwise().sum();
	} else {
		throw std::runtime_error("Only rows and columns accepted.");
	}

	return std::make_unique<Variable>(out);
}

Matrix ReduceSum::differentiate() { return left->get_output(); }
