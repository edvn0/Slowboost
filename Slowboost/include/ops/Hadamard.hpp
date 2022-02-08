//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_HADAMARD_HPP
#define COMP_GRAPH_HADAMARD_HPP

#include "Operation.hpp"

class Hadamard : public Operation {
public:
	~Hadamard() override = default;
	explicit Hadamard(SharedNodePtr left, SharedNodePtr right);
	SharedNodePtr execute() override;
	Matrix differentiate() override;
};

#endif // COMP_GRAPH_HADAMARD_HPP
