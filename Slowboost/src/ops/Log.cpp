//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Log.hpp"

#include <iostream>
#include <xtensor/xio.hpp>

Log::Log(SharedNodePtr value)
	: Operation(std::move(value), {}, "Log"){};

SharedNodePtr Log::execute()
{
	Array matrix = left->get_output();

	return std::make_unique<Variable>(xt::log(matrix));
}

std::array<Matrix, 2> Log::backprop(const Matrix& wrt)
{
	auto A = left->get_output();
    
    
	return { wrt / (A + 1e-9), {} };
}
