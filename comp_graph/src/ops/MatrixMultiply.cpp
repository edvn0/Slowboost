//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/MatrixMultiply.hpp"

MatrixMultiply::MatrixMultiply(NodePtr left, NodePtr right)
	: Operation(std::move(left), std::move(right), "MatrixMultiply"){};

NodePtr MatrixMultiply::execute()
{
	auto l = left->get_output();
	auto r = right->get_output();
	return std::make_unique<Variable>(l * r);
}

Matrix MatrixMultiply::differentiate() { return Matrix(); }
