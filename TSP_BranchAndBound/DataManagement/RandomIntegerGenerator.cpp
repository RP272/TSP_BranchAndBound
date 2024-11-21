#include "RandomIntegerGenerator.hpp"

RandomIntegerGenerator::RandomIntegerGenerator(int min, int max) : rng(rd()), uni(min, max) {};

int RandomIntegerGenerator::generate()
{
	return uni(rng);
}