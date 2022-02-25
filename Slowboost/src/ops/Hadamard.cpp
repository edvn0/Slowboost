//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Hadamard.hpp"

Hadamard::Hadamard(SharedNodePtr left, SharedNodePtr right)
	: Operation(std::move(left), std::move(right), "Hadamard"){};

SharedNodePtr Hadamard::execute()
{
	Matrix hadamard = left->get_output() * right->get_output();
	INFO("Hadamard Shape: {} x {}", hadamard.shape(0), hadamard.shape(1));
	return std::make_unique<Variable>(hadamard);
}

std::array<Matrix, 2> Hadamard::backprop(const Matrix& wrt)
{
	auto A = left->get_output();
	auto B = right->get_output();
	Array had = wrt;
	return { B * had, A * had };
}
