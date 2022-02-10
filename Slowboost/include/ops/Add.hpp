//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_ADD_HPP
#define COMP_GRAPH_ADD_HPP

#include "Operation.hpp"

class Add : public Operation {
public:
	~Add() override = default;
	Add(SharedNodePtr left, SharedNodePtr right);
	SharedNodePtr execute() override;
	std::array<Matrix, 2> backprop(const Matrix& wrt) override;
};

#endif // COMP_GRAPH_ADD_HPP
