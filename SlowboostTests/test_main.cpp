//
// Created by Edwin Carlsson on 2022-02-08.
//

#include "Logger.hpp"
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
	Logger::init();
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
