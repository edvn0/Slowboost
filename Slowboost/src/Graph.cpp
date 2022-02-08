//
// Created by Edwin Carlsson on 2022-02-04.
//

#include "Graph.hpp"
#include "util/Stopwatch.hpp"
#include <iostream>

Graph::Graph(SharedNodePtr computation_graph)
	: graph(std::move(computation_graph))
{
	evaluation_chain = Session::po_traverse(graph.get());
	for (auto* node : evaluation_chain) {
		if (node->get_type() == NodeType::PH) {
			auto id = dynamic_cast<Placeholder*>(node)->id();
			if (placeholder_ids.contains(id)) {
				throw std::runtime_error("You have duplicate keys as placeholders.");
			} else {
				placeholder_ids.insert(id);
			}
		}
	}
};

Matrix Graph::evaluate(const PlaceholderMap& mapping)
{
	check_placeholder_correctness(mapping);
	Session evaluation_session(graph, evaluation_chain, mapping);
#ifdef CG_DEBUG
	SystemStopwatch stop_watch;
	auto result = evaluation_session.run();

	auto time_taken = stop_watch.elapsed_time<>();
	std::cout << "Time taken: [" << time_taken / 1000 << "] ms\n";

	return result;
#else
	return evaluation_session.run();
#endif
}

void Graph::check_placeholder_correctness(const PlaceholderMap& map)
{
	for (auto&& [key, value] : map) {
		if (!placeholder_ids.contains(key)) {
			throw std::runtime_error("Placeholder ID does not exist in this graph.");
		}
	}
}
