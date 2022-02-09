//
// Created by Edwin Carlsson on 2022-02-07.
//

#ifndef COMP_GRAPH_CSVIMPORT_HPP
#define COMP_GRAPH_CSVIMPORT_HPP

#include <eigen3/Eigen/Core>
#include <fstream>
#include <string>
#include <vector>

Eigen::MatrixXd load_csv(const std::string& path);

void write_csv(const std::string& fp, const Eigen::MatrixXd& matrix);

#endif // COMP_GRAPH_CSVIMPORT_HPP
