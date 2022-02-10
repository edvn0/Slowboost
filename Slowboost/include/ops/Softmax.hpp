//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_SOFTMAX_HPP
#define COMP_GRAPH_SOFTMAX_HPP

#include "Operation.hpp"

class Softmax : public Operation {
public:
	~Softmax() override = default;
	explicit Softmax(SharedNodePtr left);
	SharedNodePtr execute() override;
	std::array<Matrix, 2> backprop(const Matrix& wrt) override;
};

#endif // COMP_GRAPH_SIGMOID_HPP
