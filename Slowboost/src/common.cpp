//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "common.hpp"

SharedNodePtr var(Matrix&& val)
{
	auto out = std::make_shared<Variable>(val);
	return out;
}

SharedNodePtr var(const Matrix& val)
{
	auto out = std::make_shared<Variable>(val);
	return out;
}

SharedNodePtr ph(const std::string& name)
{
	auto out = std::make_shared<Placeholder>(name);
	return out;
}