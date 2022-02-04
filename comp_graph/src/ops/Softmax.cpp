//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Softmax.hpp"

Softmax::Softmax(NodePtr value)
	: Operation(std::move(value), {}, "Softmax"){};

NodePtr Softmax::execute()
{
	auto l = left->get_output();
	auto sum = l.array().exp().rowwise().sum();

	auto softmax = l.unaryExpr([sum](double d) {return exp(d)/sum.sum();});
	return std::make_unique<Variable>(softmax);
}

Matrix Softmax::differentiate() { return {}; }
