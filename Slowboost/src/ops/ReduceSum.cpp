//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/ReduceSum.hpp"

ReduceSum::ReduceSum(SharedNodePtr value, Axis axis)
	: Operation(std::move(value), {}, "ReduceSum")
	, axis(axis)
{
}

SharedNodePtr ReduceSum::execute()
{
	auto l = left->get_output();

	SHAPE("ReduceSum Input Left", l);

	if (axis == Axis::One) {
		Matrix reduced = xt::sum(l, { 1 });
		Matrix out = reduced.reshape({ -1, 1 });
		return std::make_unique<Variable>(out);
	} else if (axis == Axis::Zero) {
		Matrix reduced = xt::sum(l, { 0 });
		Matrix out = reduced.reshape({ -1, 1 });
		return std::make_unique<Variable>(out);
	} else {
		Matrix reduced = xt::sum(l);
		Matrix out = reduced.reshape({ 1, 1 });
		return std::make_unique<Variable>(out);
	}
}

std::array<Matrix, 2> ReduceSum::backprop(double wrt) { return {}; }

std::array<Matrix, 2> ReduceSum::backprop(const Matrix& wrt) { return {}; }
