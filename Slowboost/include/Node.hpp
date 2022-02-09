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
	SharedNodePtr left;
	SharedNodePtr right;

	Matrix output;
	SharedNodePtr consumer;

	NodeType type;

	[[maybe_unused]] std::string debug_name;

public:
	virtual ~Node() = default;

	explicit Node(std::string debug_name, NodeType type = NodeType::NONE, SharedNodePtr left = nullptr,
		SharedNodePtr right = nullptr);

	virtual SharedNodePtr execute() = 0;

public:
	SharedNodePtr& get_left() { return left; }
	SharedNodePtr& get_right() { return right; }
	Matrix get_output() { return output; };
	SharedNodePtr get_consumer() { return consumer; }

	void set_output(Matrix matrix) { output = std::move(matrix); };
	void set_consumer(SharedNodePtr node) { consumer = std::move(node); };

	[[nodiscard]] NodeType get_type() const { return type; };
	[[nodiscard]] Matrix get_output() const { return output; }

	std::string_view get_identifier() { return debug_name; }

	virtual std::string display_node() { return {}; };
};

#endif // COMP_GRAPH_NODE_HPP
