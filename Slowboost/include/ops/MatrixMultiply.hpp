//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_MATRIXMULTIPLY_HPP
#define COMP_GRAPH_MATRIXMULTIPLY_HPP

#include "Operation.hpp"

class MatrixMultiply : public Operation {
public:
	~MatrixMultiply() override = default;
	MatrixMultiply(SharedNodePtr left, SharedNodePtr right);
	SharedNodePtr execute() override;
	std::array<Matrix, 2> backprop(const Matrix& wrt) override;
};

#endif // COMP_GRAPH_MATRIXMULTIPLY_HPP
