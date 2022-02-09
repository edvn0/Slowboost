//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_REDUCESUM_HPP
#define COMP_GRAPH_REDUCESUM_HPP

#include "Operation.hpp"

enum class Axis { Zero = 0, One = 1, None = 2 };

class ReduceSum : public Operation {
public:
	~ReduceSum() override = default;
	explicit ReduceSum(SharedNodePtr left, Axis axis = Axis::None);
	SharedNodePtr execute() override;
	Matrix differentiate() override;

private:
	Axis axis;
};

#endif // COMP_GRAPH_REDUCESUM_HPP
