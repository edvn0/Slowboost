//
// Created by Edwin Carlsson on 2022-02-04.
//

#include "Placeholder.hpp"

Placeholder::Placeholder(const std::string& name)
	: Node("Placeholder " + name, NodeType::PH)
	, identifier(name)
{
}

std::array<Matrix, 2> Placeholder::backprop(const Matrix& wrt) { return {}; }
