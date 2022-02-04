//
// Created by Edwin Carlsson on 2022-02-03.
//

#ifndef COMP_GRAPH_VARIABLE_HPP
#define COMP_GRAPH_VARIABLE_HPP

#include "Node.hpp"

class Variable : public Node {
private:
	Eigen::MatrixXd data;

public:
	~Variable() override = default;
	explicit Variable(Eigen::MatrixXd data)
		: Node("Variable",NodeType::VAR)
		, data(std::move(data)){};

	NodePtr execute() override {
		return std::make_unique<Variable>(data);
	}

	Eigen::MatrixXd get_data() { return data; }
	[[nodiscard]] Eigen::MatrixXd get_data() const { return data; }
};

#endif // COMP_GRAPH_VARIABLE_HPP
