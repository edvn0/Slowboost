//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Softmax.hpp"

#include <iostream>

Softmax::Softmax(SharedNodePtr value)
	: Operation(std::move(value), {}, "Softmax"){};

SharedNodePtr Softmax::execute()
{
	auto l = left->get_output();

	Matrix sm = Matrix::Zero(l.rows(), l.cols());
	for (long i = 0; i < l.rows(); i++) {
		double row_max = l.row(i).maxCoeff();
		auto stable = (l.row(i).array() - row_max).exp();
		sm.row(i) = stable / stable.sum();
	}

	return std::make_unique<Variable>(std::move(sm));
}

Matrix Softmax::differentiate() { return {}; }
