//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Log.hpp"

#include <iostream>

Log::Log(SharedNodePtr value)
	: Operation(std::move(value), {}, "Log"){};

SharedNodePtr Log::execute()
{
	Array matrix = left->get_output().array();

	Matrix log = matrix.log();
	return std::make_unique<Variable>(log);
}

std::array<Matrix, 2> Log::backprop(const Matrix& wrt)
{
	auto A = dynamic_cast<Variable*>(left.get())->get_data();
	return { wrt.array() / (A(0, 0) + 1e-9), {} };
}