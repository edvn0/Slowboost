//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_PLACEHOLDER_HPP
#define COMP_GRAPH_PLACEHOLDER_HPP

#include "Node.hpp"

class Placeholder : public Node {
private:
	std::string identifier;

public:
	explicit Placeholder(const std::string& identifier);

	SharedNodePtr execute() override { throw std::runtime_error("We never execute this node."); }

public:
	std::string id() { return identifier; };
	[[nodiscard]] std::string id() const { return identifier; };
};

#endif // COMP_GRAPH_PLACEHOLDER_HPP
