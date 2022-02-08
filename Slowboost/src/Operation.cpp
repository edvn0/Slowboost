//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "../include/Operation.hpp"

Operation::Operation(SharedNodePtr left, SharedNodePtr right, std::string debug_name)
	: Node(std::move(debug_name), NodeType::OP, std::move(left), std::move(right)){}
