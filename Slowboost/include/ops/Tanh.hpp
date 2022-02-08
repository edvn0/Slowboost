//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_TANH_HPP
#define COMP_GRAPH_TANH_HPP

#include "Operation.hpp"

class Tanh : public Operation {
public:
	~Tanh() override = default;
	explicit Tanh(SharedNodePtr left);
	SharedNodePtr execute() override;
	Matrix differentiate() override;

private:
	MathFunction _tanh = [](double d) { return tanh(d); };
	Derivative tanh_diff = [&](double d) { return tanh(d); };
};

#endif // COMP_GRAPH_TANH_HPP
