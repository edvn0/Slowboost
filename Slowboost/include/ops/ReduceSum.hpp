//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_REDUCESUM_HPP
#define COMP_GRAPH_REDUCESUM_HPP

#include "Operation.hpp"

class ReduceSum : public Operation {
public:
	~ReduceSum() override = default;
	explicit ReduceSum(SharedNodePtr left, int axis = 0);
	SharedNodePtr execute() override;
	Matrix differentiate() override;

private:
	int axis;
};

#endif // COMP_GRAPH_REDUCESUM_HPP
