#include "HelperFunctions.h"

int HelperFunctions::GenerateRandomNumber(int startValue, int endValue) {
	static std::random_device rd;

	static std::default_random_engine eng(rd());

	std::uniform_int_distribution<int> distr(startValue, endValue - 1);

	return distr(eng);
}