//
// Created by Edwin Carlsson on 2022-02-09.
//

#ifndef SLOWBOOSTALL_GRADIENTDESCENTOPTIMIZER_HPP
#define SLOWBOOSTALL_GRADIENTDESCENTOPTIMIZER_HPP

#include "Operation.hpp"

class GradientDescentOptimizer : public Operation {
private:
	double lr;

public:
	~GradientDescentOptimizer() override = default;
	explicit GradientDescentOptimizer(SharedNodePtr value, double lr);
	SharedNodePtr execute() override;
	Matrix differentiate() override;
	std::array<Matrix, 2> backprop(const Matrix& wrt) override;
};

#endif // SLOWBOOSTALL_GRADIENTDESCENTOPTIMIZER_HPP
