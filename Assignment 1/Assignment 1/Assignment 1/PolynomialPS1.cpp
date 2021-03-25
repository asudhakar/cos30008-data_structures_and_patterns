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

	for (int i = fDegree; i >= 0; i--)
	{
		result.fCoeffs[i - 1] = fCoeffs[i] * i;
	}

	if (fDegree - 1 >= 0)
	{
		result.fDegree = fDegree - 1 <= MAX_POLYNOMIAL ? fDegree - 1 : MAX_POLYNOMIAL;
	}
	else
	{
		result.fDegree = 0;
	}
	
	return result;
}

Polynomial Polynomial::getIndefiniteIntegral() const {
	Polynomial result;

	if (fDegree + 1 <= MAX_POLYNOMIAL)
	{
		result.fDegree = fDegree + 1;
	}
	else
	{
		result.fDegree = MAX_POLYNOMIAL;
	}

	for (int i = result.fDegree - 1; i >= 0; i--)
	{
		result.fCoeffs[i + 1] = fCoeffs[i] / ((double)i + 1);
	}
	
	return result;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
	double low = 0;
	double high = 0;

	for (int i = fDegree; i >= 0; i--)
	{
		low += fCoeffs[i] / ((double) i + 1) * pow(aXLow, i + 1);
	}
	
	for (int i = fDegree; i >= 0; i--)
	{
		high += fCoeffs[i] / ((double)i + 1) * pow(aXHigh, i + 1);
	}

	return high - low;
}