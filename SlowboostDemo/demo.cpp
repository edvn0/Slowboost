//
// Created by Edwin Carlsson on 2022-02-08.
//

#include <iostream>

#include "EigenRand/EigenRand"
#include "Gradients.hpp"
#include "Graph.hpp"
#include "Session.hpp"
#include "common.hpp"
#include "ops/Add.hpp"
#include "ops/Hadamard.hpp"
#include "ops/LeakyRelu.hpp"
#include "ops/Log.hpp"
#include "ops/MatrixMultiply.hpp"
#include "ops/Negative.hpp"
#include "ops/ReduceSum.hpp"
#include "ops/Softmax.hpp"
#include "random.hpp"

int main()
{
	static auto constexpr input_size = 2;
	static auto constexpr output_size = 2;
	static auto constexpr h1_output_size = 50;
	static auto constexpr h2_output_size = 100;

	auto gen = normal_generator();

	auto red_points = Matrix::Random(50, input_size) - 2 * Matrix::Ones(50, input_size);
	auto blue_points = Matrix::Random(50, input_size) + 2 * Matrix::Ones(50, input_size);
	Matrix all_points(red_points.rows() + blue_points.rows(), red_points.cols());
	all_points << blue_points, red_points;
	Matrix correct_identifier(100, output_size);
	correct_identifier << 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
		0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1;
	// MLP
	// Softmax(Tanh(Tanh(Ax + B)z + C)y + E)
	Matrix wH1, bH1;
	wH1 = Eigen::Rand::normal<Matrix>(input_size, h1_output_size, gen, 1.0, 1000);
	bH1 = Eigen::Rand::normal<Matrix>(h1_output_size, 1, gen, 1.0, 1000);
	Matrix wH2, bH2;
	wH2 = Eigen::Rand::normal<Matrix>(h1_output_size, h2_output_size, gen, 1.0, 1000);
	bH2 = Eigen::Rand::normal<Matrix>(h2_output_size, 1, gen, 1.0, 1000);
	Matrix wO, bO;
	wO = Eigen::Rand::normal<Matrix>(h2_output_size, output_size, gen, 1.0, 1000);
	bO = Eigen::Rand::normal<Matrix>(output_size, 1, gen, 1.0, 1000);

	auto h1 = op<LeakyRelu>(op<Add>(op<MatrixMultiply>(ph("x"), var(wH1)), var(bH1)));

	auto h2 = op<LeakyRelu>(op<Add>(op<MatrixMultiply>(h1, var(wH2)), var(bH2)));

	auto p = op<Softmax>(op<Add>(op<MatrixMultiply>(h2, var(wO)), var(bO)));

	auto loss = op<Negative>(op<ReduceSum>(op<ReduceSum>(op<Hadamard>(ph("c"), op<Log>(p)), Axis::One)));

	auto mlp = Graph(p);
	auto loss_graph = Graph(loss);

	auto min = Graph(minimize(loss));

	PlaceholderMap mapping{ { "x", all_points } };
	auto estimation_output = mlp.evaluate(mapping);
	mapping.try_emplace("c", correct_identifier);
	auto loss_output = min.evaluate(mapping);

	std::cout << loss_output;

	return 0;
}
