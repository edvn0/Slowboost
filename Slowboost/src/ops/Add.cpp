//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Add.hpp"
#include "util/Enumerate.hpp"

Add::Add(SharedNodePtr left, SharedNodePtr right)
	: Operation(std::move(left), std::move(right), "Add"){};

SharedNodePtr Add::execute()
{
	auto l = left->get_output(); // M X N MATRIX
	Vector r = right->get_output(); // M X 1 VECTOR

	Matrix addition = l.array().rowwise() + r.transpose().array();

	return std::make_unique<Variable>(addition);
}

std::array<Matrix, 2> Add::backprop(const Matrix& wrt)
{
	auto wrt_left = left->get_output();
	auto wrt_right = right->get_output();

	Matrix grad_wrt_left = wrt;
	Matrix grad_wrt_right = wrt;

	// ndim >
	auto ndim = [](const Matrix& mat) { return int(bool(mat.rows() > 1) + bool(mat.cols() > 1)); };
	if (ndim(grad_wrt_left) > ndim(wrt_left)) {
		grad_wrt_left = grad_wrt_left.colwise().sum();
	}
	std::vector<long> left_shape = { wrt_left.rows(), wrt_right.cols() };
	for (auto&& [index, size] : enumerate(left_shape)) {
		if (size == 1) {
			grad_wrt_left = grad_wrt_left.rowwise().sum();
		}
	}

	if (ndim(grad_wrt_right) > ndim(wrt_left)) {
		grad_wrt_right = grad_wrt_right.colwise().sum();
	}
	std::vector<long> right_shape = { wrt_left.rows(), wrt_right.cols() };
	for (auto&& [index, size] : enumerate(right_shape)) {
		if (size == 1) {
			grad_wrt_right = grad_wrt_right.rowwise().sum();
		}
	}

	return { grad_wrt_left, grad_wrt_right };
}
