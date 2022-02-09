//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "Session.hpp"
#include "Operation.hpp"
#include "Placeholder.hpp"
#include "Variable.hpp"

void Session::recurse_po(Node* op, EvaluationOrder& out)
{
	if (op->get_type() == NodeType::OP) {
		auto left = op->get_left().get();
		auto right = op->get_right().get();
		if (left) {
			recurse_po(left, out);
		}
		if (right) {
			recurse_po(right, out);
		}
	}
	out.push_back(op);
}

EvaluationOrder Session::po_traverse(Node* op)
{
	EvaluationOrder out;
	out.reserve(50);
	recurse_po(op, out);
	return out;
}

Matrix Session::run()
{
	for (Node* node : order) {
		auto type = node->get_type();

		switch (type) {
		case NodeType::NONE: {
			throw std::runtime_error("Not here.");
		}
		case NodeType::OP: {
			auto output = dynamic_cast<Operation*>(node);
			SharedNodePtr result = output->execute();

			auto res_op = dynamic_cast<Variable*>(result.get());
			auto res_data = res_op->get_data();
			node->set_output(res_data);
			break;
		}
		case NodeType::VAR: {
			auto var = dynamic_cast<Variable*>(node);
			auto data = var->get_data();
			node->set_output(data);
			break;
		}
		case NodeType::PH: {
			auto a = dynamic_cast<Placeholder*>(node);
			auto output = map.at(a->id());
			node->set_output(output);
			break;
		}
		}
	}
	return graph->get_output();
}