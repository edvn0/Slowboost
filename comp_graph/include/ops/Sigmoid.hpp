//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_SIGMOID_HPP
#define COMP_GRAPH_SIGMOID_HPP

#include "Operation.hpp"

class Sigmoid : public Operation {
public:
	~Sigmoid() override = default;
	explicit Sigmoid(NodePtr left);
	NodePtr execute() override;
	Matrix differentiate() override;

private:
	MathFunction sigmoid = [](double d) { return 1.0 / (1 + exp(d)); };
	Derivative sigmoid_diff = [&](double d) { return sigmoid(d) * (1 - sigmoid(d)); };
};

#endif // COMP_GRAPH_SIGMOID_HPP
