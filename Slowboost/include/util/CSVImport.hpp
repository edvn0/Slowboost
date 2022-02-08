//
// Created by Edwin Carlsson on 2022-02-07.
//

#ifndef COMP_GRAPH_CSVIMPORT_HPP
#define COMP_GRAPH_CSVIMPORT_HPP

#include <eigen3/Eigen/Core>
#include <fstream>
#include <vector>

template <typename M> M load_csv(const std::string& path)
{
	std::ifstream in_data;
	in_data.open(path);
	std::string line;
	std::vector<double> values;
	uint rows = 0;
	while (std::getline(in_data, line)) {
		std::stringstream line_stream(line);
		std::string cell;
		while (std::getline(line_stream, cell, ',')) {
			values.push_back(std::stod(cell));
		}
		++rows;
	}
	return Map<
		const Eigen::Matrix<typename M::Scalar, M::RowsAtCompileTime, M::ColsAtCompileTime, Eigen::RowMajor>>(
		values.data(), rows, values.size() / rows);
}

#endif // COMP_GRAPH_CSVIMPORT_HPP
