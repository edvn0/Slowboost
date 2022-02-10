//
// Created by Edwin Carlsson on 2022-02-07.
//

#ifndef COMP_GRAPH_LEAKYRELU_H
#define COMP_GRAPH_LEAKYRELU_H

#include "Operation.hpp"

class LeakyRelu : public Operation {
public:
	~LeakyRelu() override = default;
	explicit LeakyRelu(SharedNodePtr value, double leak = 0.01);
	SharedNodePtr execute() override;
	std::array<Matrix, 2> backprop(const Matrix& wrt) override;

private:
	double leak_factor;

	MathFunction leaky_relu = [&](double d) {
		if (d > 0) {
			return d;
		} else {
			return d * leak_factor;
		}
	};
};

#endif // COMP_GRAPH_LEAKYRELU_H
