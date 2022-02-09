#include "random.hpp"

Eigen::Rand::Vmt19937_64& normal_generator()
{
	static Eigen::Rand::Vmt19937_64 normal_generator;
	return normal_generator;
}