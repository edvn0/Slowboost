//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_NODE_HPP
#define COMP_GRAPH_NODE_HPP

#include <ostream>
#include <string>
#include <utility>
#include <vector>

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

	NodeType type;

	std::string debug_name;
	Node* consumer = nullptr;

public:
	virtual ~Node() = default;

	explicit Node(std::string debug_name, NodeType type = NodeType::NONE, SharedNodePtr left = nullptr,
		SharedNodePtr right = nullptr);

	virtual SharedNodePtr execute() = 0;

	void add_consumers()
	{
		if (left)
			left->set_consumer(this);
		if (right)
			right->set_consumer(this);
	};

	virtual std::string display_node() { return {}; };

	virtual std::array<Matrix, 2> backprop(const Matrix& wrt) = 0;
	virtual std::array<Matrix, 2> backprop(double wrt) { return backprop(Matrix::Constant(1, 1, wrt)); };

public:
	SharedNodePtr& get_left() { return left; }
	SharedNodePtr& get_right() { return right; }

	Matrix get_output() { return output; };
	Matrix get_output() const { return output; }
	void set_output(Matrix matrix) { output = std::move(matrix); };

	int inputs() { return bool(left) + bool(right); }

	void set_consumer(Node* node) { consumer = node; };
	Node* get_consumer() { return consumer; }

	NodeType get_type() const { return type; };
	std::string_view get_identifier() { return debug_name; }
};

#endif // COMP_GRAPH_NODE_HPP
