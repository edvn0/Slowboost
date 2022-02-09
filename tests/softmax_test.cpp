//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "gtest/gtest.h"

#include "Graph.hpp"
#include "common.hpp"
#include "ops/Add.hpp"
#include "ops/Hadamard.hpp"
#include "ops/Log.hpp"
#include "ops/MatrixMultiply.hpp"
#include "ops/Negative.hpp"
#include "ops/ReduceSum.hpp"
#include "ops/Softmax.hpp"

TEST(SpecificationCorrectness, Softmax)
{
	auto red_points = Matrix::Random(50, 2) - 2 * Matrix::Ones(50, 2);
	auto blue_points = Matrix::Random(50, 2) + 2 * Matrix::Ones(50, 2);
	Matrix all_points(red_points.rows() + blue_points.rows(), red_points.cols());
	all_points << blue_points, red_points;
	Matrix correct_identifier(100, 2);
	correct_identifier << 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1;

	Matrix w(2, 2);
	w << 1, -1, 1, -1;
	Matrix b(2, 1);
	b << 0, 0;
	auto W = var(w);
	auto basis = var(b);
	auto p = op<Softmax>(op<Add>(op<MatrixMultiply>(ph("x"), W), basis));

	auto J = op<Negative>(op<ReduceSum>(op<ReduceSum>(op<Hadamard>(ph("c"), op<Log>(p)), Axis::One)));
	auto loss_graph = Graph(J);
	double correct = 0.104612;
	auto loss = loss_graph.evaluate({ { "x", all_points }, { "c", correct_identifier } });
	ASSERT_NEAR(loss.coeff(0), correct, 1e-5);
}
