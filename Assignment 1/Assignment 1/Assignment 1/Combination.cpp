#include "Combination.h"

using namespace std;

Combination::Combination(unsigned int aN, unsigned int aK) {
	fN = aN;
	fK = aK;
}

unsigned int Combination::getN() const {
	return fN;
}

unsigned int Combination::getK() const {
	return fK;
}

unsigned long long Combination::operator()() const {
	if (fK > fN) return 0;
	if (fK == fN) return 1;

	unsigned long long lResult = fN;
	for (int k = 1; k <= fK; k++)
	{
		lResult *= ((unsigned long long)fN - k + 1);
		lResult /= k;
	}
	return lResult;
}