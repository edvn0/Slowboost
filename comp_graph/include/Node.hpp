//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_NODE_HPP
#define COMP_GRAPH_NODE_HPP

#include <ostream>
#include <string>
#include <utility>

#include "types.hpp"

enum class NodeType : size_t { NONE = 0, OP = 1, VAR = 2, PH = 3 };

class Placeholder;
class Variable;
class Operation;
class Add;

class Node {
protected:
	NodePtr left;
	NodePtr right;

	Matrix output;

	NodeType type;

	[[maybe_unused]] std::string debug_name;

public:
	virtual ~Node() = default;

	explicit Node(
		std::string debug_name, NodeType type = NodeType::NONE, NodePtr left = nullptr, NodePtr right = nullptr);

	virtual NodePtr execute() = 0;

public:
	NodePtr& get_left() { return left; }
	NodePtr& get_right() { return right; }
	Matrix get_output() { return output; };

	void set_output(Matrix matrix) { output = std::move(matrix); };

	[[nodiscard]] NodeType get_type() const { return type; };
	[[nodiscard]] Matrix get_output() const { return output; }
};

#endif // COMP_GRAPH_NODE_HPP
