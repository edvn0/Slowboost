//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Hadamard.hpp"

Hadamard::Hadamard(SharedNodePtr left, SharedNodePtr right)
	: Operation(std::move(left), std::move(right), "Hadamard"){};

SharedNodePtr Hadamard::execute()
{
	return std::make_unique<Variable>(left->get_output().array() * right->get_output().array());
}

Matrix Hadamard::differentiate() { return left->get_output(); }
