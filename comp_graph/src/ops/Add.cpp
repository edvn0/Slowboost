//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Add.hpp"

Add::Add(NodePtr left, NodePtr right)
	: Operation(std::move(left), std::move(right), "Add"){};

NodePtr Add::execute()
{
	auto l = left->get_output(); // M X N MATRIX
	Vector r = right->get_output(); // M X 1 VECTOR

	Matrix addition = l.array().rowwise() + r.transpose().array();

	return std::make_unique<Variable>(addition);
}

Matrix Add::differentiate() { return Matrix(); }
