//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_MATRIXMULTIPLY_HPP
#define COMP_GRAPH_MATRIXMULTIPLY_HPP

#include "Operation.hpp"

class MatrixMultiply : public Operation {
public:
	~MatrixMultiply() override = default;
	MatrixMultiply(NodePtr left, NodePtr right);
	NodePtr execute() override;
	Matrix differentiate() override;
};

#endif // COMP_GRAPH_MATRIXMULTIPLY_HPP
