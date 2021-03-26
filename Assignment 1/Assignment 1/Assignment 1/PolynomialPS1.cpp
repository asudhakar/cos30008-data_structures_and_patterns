#include "Polynomial.h"
#include <math.h>

using namespace std;

double Polynomial::operator()(double aX) const {
	double lResult = 0;

	for (int i = fDegree; i >= 0; i--)
	{
		lResult += fCoeffs[i] * pow(aX, i);
	}

	return lResult;
}

Polynomial Polynomial::getDifferential() const {
	Polynomial lResult;

	for (int i = fDegree; i >= 0; i--)
	{
		lResult.fCoeffs[i - 1] = fCoeffs[i] * i;
	}

	if (fDegree - 1 >= 0)
	{
		lResult.fDegree = fDegree - 1 <= MAX_POLYNOMIAL ? fDegree - 1 : MAX_POLYNOMIAL;
	}
	else
	{
		lResult.fDegree = 0;
	}
	
	return lResult;
}

Polynomial Polynomial::getIndefiniteIntegral() const {
	Polynomial lResult;

	if (fDegree + 1 <= MAX_POLYNOMIAL)
	{
		lResult.fDegree = fDegree + 1;
	}
	else
	{
		lResult.fDegree = MAX_POLYNOMIAL;
	}

	for (int i = lResult.fDegree - 1; i >= 0; i--)
	{
		lResult.fCoeffs[i + 1] = fCoeffs[i] / ((double)i + 1);
	}
	
	return lResult;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
	double lLow = 0;
	double lHigh = 0;

	for (int i = fDegree; i >= 0; i--)
	{
		lLow += fCoeffs[i] / ((double) i + 1) * pow(aXLow, i + 1);
	}
	
	for (int i = fDegree; i >= 0; i--)
	{
		lHigh += fCoeffs[i] / ((double)i + 1) * pow(aXHigh, i + 1);
	}

	return lHigh - lLow;
}