//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "ops/Add.hpp"
#include "util/Enumerate.hpp"

#include <xtensor-blas/xlinalg.hpp>

static constexpr auto LIMIT_WEIRD_SHAPE = 10'000;

Add::Add(SharedNodePtr left, SharedNodePtr right)
	: Operation(std::move(left), std::move(right), "Add"){};

SharedNodePtr Add::execute()
{
	auto a = xt::transpose(left->get_output());
	auto b = right->get_output();

	auto c = xt::broadcast(a + b, { b.shape(0), b.shape(1) });

	INFO("Add Shape: {} x {}", c.shape(0), c.shape(1));

	return std::make_unique<Variable>(xt::transpose(c));
}

std::array<Matrix, 2> Add::backprop(const Matrix& wrt)
{
	auto wrt_left = left->get_output();
	auto wrt_right = right->get_output();

	Matrix grad_wrt_left = wrt;
	Matrix grad_wrt_right = wrt;

	// ndim >
	auto ndim = [](const Matrix& mat) { return int(bool(mat.shape(0) > 1) + bool(mat.shape(1) > 1)); };

	if (ndim(grad_wrt_left) > ndim(wrt_left)) {
		grad_wrt_left = xt::sum(grad_wrt_left, { 0 });
	}
	std::vector<size_t> left_shape = { wrt_left.shape(0), wrt_left.shape(1) };
	for (auto&& [index, size] : enumerate(left_shape)) {
		if (size == 1 && grad_wrt_left.shape(1) < LIMIT_WEIRD_SHAPE) {
			grad_wrt_left = xt::sum(grad_wrt_left, { index });
		}
	}

	if (ndim(grad_wrt_right) > ndim(wrt_right)) {
		grad_wrt_right = xt::sum(grad_wrt_right, { 0 });
	}
	std::vector<size_t> right_shape = { wrt_right.shape(0), wrt_right.shape(1) };
	for (auto&& [index, size] : enumerate(right_shape)) {
		if (size == 1 && grad_wrt_right.shape(1) < LIMIT_WEIRD_SHAPE) {
			grad_wrt_right = xt::sum(grad_wrt_right, { index });
		}
	}

	return { grad_wrt_left, grad_wrt_right };
}
