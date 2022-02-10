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
	std::array<Matrix, 2> backprop(double wrt) override;
	std::array<Matrix, 2> backprop(const Matrix& wrt) override;

private:
	Axis axis;

	int axis_value()
	{
		switch (axis) {
		case Axis::Zero:
			return 0;
		case Axis::One:
			return 1;
		case Axis::None:
			return -1;
		}
	}
};

#endif // COMP_GRAPH_REDUCESUM_HPP
