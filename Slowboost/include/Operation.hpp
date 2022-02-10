//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_OPERATION_HPP
#define COMP_GRAPH_OPERATION_HPP

#include <utility>

#include "Node.hpp"
#include "Variable.hpp"

class Operation : public Node {
protected:
	using MathFunction = std::function<double(double)>;
	using Derivative = std::function<double(double)>;

public:
	~Operation() override = default;
	Operation(SharedNodePtr left, SharedNodePtr right, std::string debug_name = "Operation");

	SharedNodePtr execute() override = 0;

	std::array<Matrix, 2> backprop(const Matrix& wrt) override = 0;

	virtual Matrix differentiate() { return {}; };
};

#endif // COMP_GRAPH_OPERATION_HPP
