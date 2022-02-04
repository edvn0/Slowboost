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
	Operation(NodePtr left, NodePtr right, std::string debug_name = "Operation");

	NodePtr execute() override = 0;

	virtual Matrix differentiate() = 0;
};

#endif // COMP_GRAPH_OPERATION_HPP
