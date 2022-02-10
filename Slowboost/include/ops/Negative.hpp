//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_NEGATIVE_HPP
#define COMP_GRAPH_NEGATIVE_HPP

#include "Operation.hpp"

class Negative : public Operation {
public:
	~Negative() override = default;
	explicit Negative(SharedNodePtr left);
	SharedNodePtr execute() override;
	std::array<Matrix, 2> backprop(const Matrix& wrt) override;
};

#endif // COMP_GRAPH_NEGATIVE_HPP
