#include <iostream>
#include "math.h"

int main() {

	float angle = PI/2;
	float precision = 1e-4;

	assert(math::factorial(6) == 720);
	assert(math::pow(2, 8) == 256);
	assert(math::pow(2, -8) == pow(2, -8));
	assert(math::isEven(4) == true);
	assert(math::isEven(3) == false);
	assert(math::decimal(3.799f) == 0.799f);
	assert(math::decimal(-3.799f) == 0.799f);
	assert(math::mod(4,2) == 0);
	assert(math::mod(5,2) == 1);
	assert(math::mod(-5,2) == 1);
	assert(math::abs(math::mod(-5.7f,2) - 1.7f) < precision);
	assert(math::sin(angle) - std::sin(angle) < precision);
	assert(math::cos(angle) - std::cos(angle) < precision);

	return 0;
}