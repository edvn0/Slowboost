//
// Created by Edwin Carlsson on 2022-02-04.
//

#ifndef COMP_GRAPH_GRAPH_HPP
#define COMP_GRAPH_GRAPH_HPP

#include "Node.hpp"
#include "Placeholder.hpp"
#include "Session.hpp"
#include <set>

class Graph {
private:
	EvaluationOrder evaluation_chain;
	SharedNodePtr graph;
	std::set<std::string> placeholder_ids;

public:
	explicit Graph(NodePtr computation_graph);

	Matrix evaluate(const PlaceholderMap& mapping);

private:
	void check_placeholder_correctness(const PlaceholderMap& map);
};

#endif // COMP_GRAPH_GRAPH_HPP
