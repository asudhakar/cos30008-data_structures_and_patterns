// COS30008, Tutorial 3, 2021

#include "Polynomial.h"
#include <math.h>

using namespace std;

double Polynomial::operator()(double aX) const {
	double result = 0;
	for (int i = fDegree; i >= 0; i--)
	{
		result += fCoeffs[i] * pow(aX, i);
	}

	return result;
}

Polynomial Polynomial::getDifferential() const {
	Polynomial result;
	result.fDegree = fDegree - 1;
	for (int i = fDegree; i >= 0; i--)
	{
		result.fCoeffs[i] = fCoeffs[i] * i;
	}
	return result;
}

Polynomial Polynomial::getIndefiniteIntegral() const {
	Polynomial a;
	return a;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
	double b = 0;
	return b;
}