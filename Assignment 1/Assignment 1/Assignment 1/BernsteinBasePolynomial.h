
// COS30008, Problem Set 1/3, 2021

#pragma once

#include "Combination.h"

// https://en.wikipedia.org/wiki/Bernstein_polynomial
class BernsteinBasePolynomial
{
private:
    Combination fFactor;
    
public:
    
    // constructor for b(0,0)
    BernsteinBasePolynomial();

    // constructor for b(v,n)
    BernsteinBasePolynomial( unsigned int aV, unsigned int aN );
    
    // call operator to calculate Berstein base
    // polynomial for a given x (i.e., aX)
    double operator()( double aX ) const;
};
