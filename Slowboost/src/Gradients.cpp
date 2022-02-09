//
// Created by Edwin Carlsson on 2022-02-09.
//

#include "Gradients.hpp"

GradTable compute_gradients(const SharedNodePtr& loss)
{
	GradTable table;
	table[loss] = 1;

	GradSet visited;
	GradQueue queue;
	visited.insert(loss);
	queue.push(loss);

	while (!queue.empty()) {
		auto node = queue.front();
		queue.pop();

		if (node != loss) {

			table[node] = 0;

			auto output = node->get_output();
		}
	}
	return table;
}