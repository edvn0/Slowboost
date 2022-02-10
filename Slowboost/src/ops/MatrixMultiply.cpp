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

std::array<Matrix, 2> MatrixMultiply::backprop(const Matrix& wrt)
{
	auto A = dynamic_cast<Variable*>(left.get())->get_data();
	auto B = dynamic_cast<Variable*>(right.get())->get_data();
	Matrix out = Matrix::Zero(A.rows() + B.rows(), B.cols());
	return { B * wrt, A * wrt };
}
