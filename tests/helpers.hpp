//
// Created by Edwin Carlsson on 2022-02-08.
//

#ifndef SLOWBOOSTALL_HELPERS_HPP
#define SLOWBOOSTALL_HELPERS_HPP

#define EIGEN_COMPARE(a, b) EXPECT_LE(((a) - (b)).norm(), 1e-5)

#endif // SLOWBOOSTALL_HELPERS_HPP
