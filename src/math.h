#include <assert.h>
namespace math {
	#define TRIGONOMETRIC_FUNCTION_TERMS 6
	#define PI 3.14159265358979323846264338327950288

	/*
		Takes an integer n and returns its factorial (n!).
	*/
	int factorial(int n) {
		assert(n >= 0);

		if (n == 1 || n == 0)
			return 1;

		return n * factorial(n - 1);
	}

	/*
		Returns positive x.
	*/
	float abs(float x) {
		if (x < 0)
			return x * -1.0f;
		return x;
	}

	/*
		Takes an float x and a positive n and returns x elevated to the power of n (x^n).
	*/
	//TODO: treat the case of a fractional power
	float pow(float x, float n) {
		float acc = 1;
		for (int i = 0; i < abs(n); i++)
			acc *= x;
		if (n < 0)
			return 1.0f / acc;
		return 
			(float)acc;
	}

	/*
		Returns true if x is even and false if it's odd.
	*/
	bool isEven(int x) {
		if (x % 2 == 0)
			return true;
		return false;
	}
	
	/*
		Returns the decimal part of x.
	*/
	float decimal(float x) {
		float intPart = (int)x;
		return abs(x - intPart);
	}

	/*
		Returns the remainder of x by n.
	*/
	float mod(float x, float n) {
		float mod = abs(x);

		while (mod >= n)
			mod -= n;

		return mod;
	}

	/*
		Takes an angle in radians and returns sin (angle) calculated as a Taylor's series.
	*/
	float sin(float angle) {
		float x = mod(angle + PI, 2 * PI) - PI;
		float signal = 1;
		float acc = 0;
		for (int i = 1; i <= TRIGONOMETRIC_FUNCTION_TERMS * 2; i = i + 2) {
			float term = pow(x, (float)i) / (float)factorial(i);
			acc += signal * term;
			signal *= -1;
		}
		return acc;
	}

	/*
		Takes an angle in radians and returns cos (angle) calculated as a Taylor's series.
	*/
	float cos(float angle) {
		float x = mod(angle + PI, 2 * PI) - PI;
		float signal = 1;
		float acc = 0;
		for (int i = 0; i < TRIGONOMETRIC_FUNCTION_TERMS * 2; i = i + 2) {
			float term = pow(x, (float)i) / factorial(i);
			acc += signal * term;
			signal *= -1;
		}
		return acc;
	}
};