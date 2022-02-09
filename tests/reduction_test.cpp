//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "gtest/gtest.h"

#include "Graph.hpp"
#include "common.hpp"
#include "helpers.hpp"
#include "ops/ReduceSum.hpp"
#include "util/MatrixIO.hpp"

TEST(SpecificationCorrectness, ReduceSum)
{
	auto read = load_csv("./mocks/test.csv");
	auto read_correct = load_csv("./mocks/test_correct_axis_one.csv");

	auto output_axis_0 = Graph::evaluate(op<ReduceSum>(var(read), Axis::Zero));
	EXPECT_NEAR(output_axis_0.coeff(0), -2.73432, 1e-5);
	EXPECT_NEAR(output_axis_0.coeff(1), 3.19357, 1e-5);

	auto output_axis_1 = Graph::evaluate(op<ReduceSum>(var(read), Axis::One));
	EIGEN_COMPARE(output_axis_1, read_correct);

	auto combined = Graph::evaluate(op<ReduceSum>(op<ReduceSum>(var(read), Axis::One)));
	EXPECT_NEAR(combined.coeff(0), 0.4592499999999875, 1e-5);
}