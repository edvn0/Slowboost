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

	Matrix dot = xt::linalg::dot(l, r);

	INFO("Dot Shape: {} x {}", dot.shape(0), dot.shape(1));

	return std::make_unique<Variable>(dot);
}

std::array<Matrix, 2> MatrixMultiply::backprop(const Matrix& wrt)
{
	auto A = left->get_output();
	auto B = right->get_output();

	std::cout << A.shape(0) << "x" << A.shape(1) << "\n";
	std::cout << B.shape(0) << "x" << B.shape(1) << "\n";
	std::cout << wrt.shape(0) << "x" << wrt.shape(1) << "\n";

	return { xt::linalg::dot(wrt, xt::transpose(B)), xt::linalg::dot(wrt, xt::transpose(A)) };
}
