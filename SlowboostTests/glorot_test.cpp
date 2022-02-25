//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "Variable.hpp"
#include "common.hpp"
#include "gtest/gtest.h"

TEST(SpecificationCorrectness, GlorotUniformInitializer) { auto glorot = Variable::glorot_normal(2, 2); }