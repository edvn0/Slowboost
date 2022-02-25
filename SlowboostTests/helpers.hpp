//
// Created by Edwin Carlsson on 2022-02-08.
//

#ifndef SLOWBOOSTALL_HELPERS_HPP
#define SLOWBOOSTALL_HELPERS_HPP

#define EIGEN_COMPARE(a, b) EXPECT_LE(((a) - (b)).norm(), 1e-5)

#define TO_VARIABLE(a)                                                                                            \
	auto temp_var = dynamic_cast<Variable*>(a.get());                                                             \
	auto variable = temp_var->get_data()

#endif // SLOWBOOSTALL_HELPERS_HPP
