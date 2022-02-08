//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "../include/Node.hpp"

Node::Node(std::string debug_name, NodeType type, SharedNodePtr left, SharedNodePtr right)
	: debug_name(std::move(debug_name))
	, type(type)
	, left(std::move(left))
	, right(std::move(right)){};
