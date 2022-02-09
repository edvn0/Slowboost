//
// Created by Edwin Carlsson on 2022-02-03.
//

#include "../include/Variable.hpp"
#include "random.hpp"

SharedNodePtr Variable::glorot_uniform(size_t input_units, size_t output_units)
{
	auto in = static_cast<long>(input_units);
	auto out = static_cast<long>(output_units);
	auto denom = static_cast<double>(in + out);
	Matrix glorot = Matrix::Random(in, out) * 6.0 / denom;
	return std::make_shared<Variable>(glorot.array().sqrt());
}

SharedNodePtr Variable::glorot_normal(size_t input_units, size_t output_units)
{
	auto gen = normal_generator();
	auto in = static_cast<long>(input_units);
	auto out = static_cast<long>(output_units);
	auto denom = static_cast<double>(in + out);
	return std::make_shared<Variable>(Eigen::Rand::normal<Matrix>(in, out, gen, 0, sqrt(2 / denom)));
}

std::string Variable::display_node()
{
	std::stringstream a;
	a << data;
	return a.str();
}
