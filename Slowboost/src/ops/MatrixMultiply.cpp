//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/MatrixMultiply.hpp"

MatrixMultiply::MatrixMultiply(SharedNodePtr left, SharedNodePtr right)
	: Operation(std::move(left), std::move(right), "MatrixMultiply"){};

SharedNodePtr MatrixMultiply::execute()
{
	auto l = left->get_output();
	auto r = right->get_output();
	return std::make_unique<Variable>(l * r);
}

Matrix MatrixMultiply::differentiate() { return Matrix(); }
