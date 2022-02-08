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

Matrix Log::differentiate() { return left->get_output(); }
