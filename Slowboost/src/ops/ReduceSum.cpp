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

std::array<Matrix, 2> ReduceSum::backprop(double wrt)
{
	std::array<long, 2> shape = { left->get_output().rows(), left->get_output().cols() };
	shape[axis_value()] = 1;
	std::array<long, 2> scale = { left->get_output().rows() / shape[0], left->get_output().cols() / shape[1] };
	return { Matrix::Constant(shape[0] * scale[0], scale[1], wrt), {} };
}

std::array<Matrix, 2> ReduceSum::backprop(const Matrix& wrt)
{
	std::array<long, 2> shape = { left->get_output().rows(), left->get_output().cols() };
	shape[axis_value()] = 1;
	std::array<long, 2> scale = { left->get_output().rows() / shape[0], left->get_output().cols() / shape[1] };

	Matrix out(scale[0] * shape[0], scale[0]);
	for (long i = 0; i < scale[0] * shape[0]; i++) {
		out(i, 0) = wrt(0, 0);
	}
	return { out, {} };
}
