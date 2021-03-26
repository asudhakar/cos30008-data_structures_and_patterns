#include "BernsteinBasePolynomial.h"
#include <math.h>

BernsteinBasePolynomial::BernsteinBasePolynomial() : fFactor(0, 0) {}

BernsteinBasePolynomial::BernsteinBasePolynomial(unsigned int aV, unsigned int aN) : fFactor(aN, aV) {}

double BernsteinBasePolynomial::operator()(double aX) const {
	return fFactor() * pow(aX, fFactor.getK()) * pow((1 - aX), (fFactor.getN() - fFactor.getK()));
}