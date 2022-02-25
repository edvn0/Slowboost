//
// Created by Edwin Carlsson on 2022-02-08.
//

#include <iostream>

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

#include <xtensor/xio.hpp>
#include <xtensor/xpad.hpp>
#include <xtensor/xrandom.hpp>

int main()
{
	Logger::init();

	static auto constexpr input_size = 2;
	static auto constexpr output_size = 2;
	static auto constexpr h1_output_size = 50;
	static auto constexpr h2_output_size = 100;

	Matrix red_points = xt::random::randn<double>({ 50, 2 }) - 2 * xt::ones<double>({ 50, 2 });
	Matrix blue_points = xt::random::randn<double>({ 50, 2 }) + 2 * xt::ones<double>({ 50, 2 });

	auto all_points = xt::vstack(xtuple(red_points, blue_points));

	Matrix red_correct = { { 1, 0 } };
	Matrix blue_correct = { { 0, 1 } };
	Matrix correct_id_red = xt::tile(red_correct, { 50, 1 });
	Matrix correct_id_blue = xt::tile(blue_correct, { 50, 1 });

	auto correct_identifier = xt::vstack(xtuple(correct_id_red, correct_id_blue));

	SHAPE("Correct Identifiers", correct_identifier);

	// MLP
	// Softmax(Tanh(Tanh(Ax + B)z + C)y + E)
	auto w = Variable::glorot_uniform(2, 2);
	auto b = Variable::glorot_uniform(2, 1);
	auto p = op<Softmax>(op<Add>(op<MatrixMultiply>(ph("x"), w), b));

	auto loss = op<Negative>(op<ReduceSum>(op<ReduceSum>(op<Hadamard>(ph("c"), op<Log>(p)), Axis::One)));

	auto mlp = Graph(p);
	auto loss_graph = Graph(loss);

	auto min = Graph(minimize(loss));

	PlaceholderMap mapping{ { "x", all_points } };
	Matrix estimation_output = mlp.evaluate(mapping);

	mapping.try_emplace("c", correct_identifier);
	auto loss_output = loss_graph.evaluate(mapping);

	INFO("{}", loss_output);

	return 0;
}
