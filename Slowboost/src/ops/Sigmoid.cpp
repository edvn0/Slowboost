//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Sigmoid.hpp"

Sigmoid::Sigmoid(SharedNodePtr value)
	: Operation(std::move(value), {}, "Sigmoid"){};

SharedNodePtr Sigmoid::execute()
{
	auto l = left->get_output();
	return std::make_unique<Variable>(l.unaryExpr(sigmoid));
}

Matrix Sigmoid::differentiate() { return left->get_output().unaryExpr(sigmoid_diff); }
