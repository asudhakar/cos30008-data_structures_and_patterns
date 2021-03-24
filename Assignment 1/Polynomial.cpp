// COS30008, Tutorial 3, 2021

#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial()
{
	fDegree = 0;

	for ( int i = 0; i < MAX_DEGREE+1; i++ )
	{
		fCoeffs[i] = 0.0;
	}
}

Polynomial Polynomial::operator*( const Polynomial& aRight ) const
{
    // C = A * B
    
	Polynomial Result;
    
    Result.fDegree = fDegree + aRight.fDegree;
    
    for ( int i = 0; i <= fDegree; i++ )
    {
        for ( int j = 0; j <= aRight.fDegree; j++ )
        {
            Result.fCoeffs[i+j] += fCoeffs[i] * aRight.fCoeffs[j];
        }
    }
    
	return Result;
}

ostream& operator<<( ostream& aOStream, const Polynomial& aObject )
{
    bool lMustPrintPlus = false;
    
    for ( int i = aObject.fDegree; i >= 0; i-- )
    {
        if ( aObject.fCoeffs[i] != 0.0 )
        {
            if ( lMustPrintPlus )
            {
                aOStream << " + ";
            }
            else
            {
                lMustPrintPlus = true;
            }
            
            aOStream << aObject.fCoeffs[i] << "x^" << i;
        }
    }
                
    if (!lMustPrintPlus)
    {
        aOStream << 0;
    }
    
    return aOStream;
}

bool Polynomial::operator==( const Polynomial& aRHS ) const
{
    bool Result = fDegree == aRHS.fDegree;
    
    for ( int i = 0; Result && i <= fDegree; i++ )
    {
        if ( fCoeffs[i] != aRHS.fCoeffs[i] )
        {
            Result = false;
        }
    }
    
    return Result;
}

double Polynomial::operator()(double aX) const {

}

Polynomial Polynomial::getDifferential() const {

}

Polynomial Polynomial::getIndefiniteIntegral() const {

}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {

}


istream& operator>>( istream& aIStream, Polynomial& aObject )
{
	// read degree
    int lDegree;
	
    aIStream >> lDegree;

    // added safety checks
    if ( lDegree >= 0 )
    {
        aObject.fDegree = lDegree <= MAX_POLYNOMIAL ? lDegree : MAX_POLYNOMIAL;
    }
    else
    {
        aObject.fDegree = 0;
    }

	// read coefficients (assume sound input)
    for ( int i = aObject.fDegree; i >= 0; i-- )
	{
		aIStream >> aObject.fCoeffs[i];
	}

	return aIStream;
}
