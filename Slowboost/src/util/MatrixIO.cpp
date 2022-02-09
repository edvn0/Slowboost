//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "util/MatrixIO.hpp"

const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n");

Eigen::MatrixXd load_csv(const std::string& path)
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
	return Eigen::Map<const Eigen::Matrix<typename Eigen::MatrixXd::Scalar, Eigen::MatrixXd::RowsAtCompileTime,
		Eigen::MatrixXd::ColsAtCompileTime,
		Eigen::RowMajor>>(values.data(), rows, values.size()/rows);
}

void write_csv(const std::string& fp, const Eigen::MatrixXd& matrix)
{
	std::ofstream file(fp.c_str());
	file << matrix.format(CSVFormat);
}
