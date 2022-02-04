//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_SESSION_HPP
#define COMP_GRAPH_SESSION_HPP

#include <unordered_map>
#include <utility>
#include <vector>

#include "Node.hpp"

using PlaceholderMap = std::unordered_map<std::string, Matrix>;
using EvaluationOrder = std::vector<Node*>;

class Session {

private:
	EvaluationOrder order;
	SharedNodePtr graph;
	PlaceholderMap map;

public:
	Session(SharedNodePtr  graph, EvaluationOrder  order, PlaceholderMap map)
		: graph(std::move(graph))
		, order(std::move(order))
		, map(std::move(map)){};

	Matrix run();

public:
	static void recurse_po(Node* op, EvaluationOrder& out);
	static EvaluationOrder po_traverse(Node* op);
};

#endif // COMP_GRAPH_SESSION_HPP
