//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "common.hpp"

SharedNodePtr var(Matrix&& val) { return std::make_shared<Variable>(val); }

SharedNodePtr var(const Matrix& val) { return std::make_shared<Variable>(val); }

SharedNodePtr ph(const std::string& name) { return std::make_shared<Placeholder>(name); }