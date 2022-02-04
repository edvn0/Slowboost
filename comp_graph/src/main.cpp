#include <iostream>

#include "Graph.hpp"
#include "Session.hpp"
#include "common.hpp"
#include "ops/Add.hpp"
#include "ops/MatrixMultiply.hpp"
#include "ops/Softmax.hpp"
#include "ops/Tanh.hpp"

int main()
{
	auto constexpr input_size = 30;
	auto constexpr output_size = 2;
	auto constexpr h1_output_size = 50;
	auto constexpr h2_output_size = 100;
	// MLP
	// Softmax(Tanh(Tanh(Ax + B)z + C)y + E)
	Matrix wH1, bH1;
	wH1 = Matrix::Random(input_size, h1_output_size);
	bH1 = Matrix::Random(h1_output_size, 1);
	Matrix wH2, bH2;
	wH2 = Matrix::Random(h1_output_size, h2_output_size);
	bH2 = Matrix::Random(h2_output_size, 1);
	Matrix wO, bO;
	wO = Matrix::Random(h2_output_size, output_size);
	bO = Matrix::Random(output_size, 1);

	auto h1 = op<Tanh>(op<Add>(op<MatrixMultiply>(ph("x"), var(wH1)), var(bH1)));

	auto h2 = op<Tanh>(op<Add>(op<MatrixMultiply>(std::move(h1), var(wH2)), var(bH2)));

	auto mlp = Graph(op<Softmax>(op<Add>(op<MatrixMultiply>(std::move(h2), var(wO)), var(bO))));

	Matrix x = Matrix::Ones(1000, input_size);

	PlaceholderMap mapping{ { "x", x } };
	auto output = mlp.evaluate(mapping);

	std::cout << output;

	return 0;
}
