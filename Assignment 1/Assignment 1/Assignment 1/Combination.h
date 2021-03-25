
// COS30008, Problem Set 1/2, 2021

#pragma once

class Combination
{
private:
    unsigned int fN;
    unsigned int fK;
    
public:

    // constructor for combination n over k
    Combination( unsigned int aN, unsigned int aK );

    unsigned int getN() const;
    unsigned int getK() const;

    // call operator to calculate n over k
    // We do not want to evaluate factorials. 
    // Rather, we use this method
    // 
    //   n      (n-0)    (n-1)         (n - (k - 1))
    // (   ) =  ----- *  ----- * ... * -------------  
    //   k        1        2                 k
    // 
    // which maps to a simple for-loop over 64-bit values.
    // https://en.wikipedia.org/wiki/Combination
    unsigned long long operator()() const;
};
