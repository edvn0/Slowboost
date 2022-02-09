//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_VARIABLE_HPP
#define COMP_GRAPH_VARIABLE_HPP

#include "Node.hpp"

class Variable : public Node {
private:
	Matrix data;

public:
	~Variable() override = default;
	explicit Variable(Matrix data)
		: Node("Variable", NodeType::VAR)
		, data(std::move(data)){};

	SharedNodePtr execute() override { return std::make_shared<Variable>(data); }

	std::string display_node() override;

	Matrix get_data() { return data; }
	[[nodiscard]] Matrix get_data() const { return data; }

public:
	static SharedNodePtr glorot_uniform(size_t input_units, size_t output_units);
	static SharedNodePtr glorot_normal(size_t input_units, size_t output_units);
};

#endif // COMP_GRAPH_VARIABLE_HPP
