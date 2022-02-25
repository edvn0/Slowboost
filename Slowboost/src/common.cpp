//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "common.hpp"

#ifdef SLOWBOOST_DEBUG

SharedNodePtr debug_var(Matrix&& val)
{
	auto out = std::make_shared<Variable>(val);
	out->set_output(val);
	return out;
}

SharedNodePtr debug_var(const Matrix& val)
{
	auto out = std::make_shared<Variable>(val);
	out->set_output(val);
	return out;
}

#endif

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