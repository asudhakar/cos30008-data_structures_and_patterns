#include "IntVector.h"
#include <iostream>

using namespace std;

IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
	fNumberOfElements = aNumberOfElements;
	fElements = new int[fNumberOfElements]; 
	
	for (size_t i = 0; i < fNumberOfElements; i++) { 
		fElements[i] = aArrayOfIntegers[i]; 
	} 
}

IntVector::~IntVector()
{
	delete fElements;
}

size_t IntVector::size() const {
	return fNumberOfElements;
}

void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex) {
	if (aSourceIndex == aTargetIndex) {
		throw out_of_range("Can't swap the same index.");
	}

	if (aSourceIndex >= fNumberOfElements) {
		throw out_of_range("Illegal Source Vector Index.");
	}

	if (aTargetIndex >= fNumberOfElements) {
		throw out_of_range("Illegal Target Vector Index.");
	}

	int lBuffer = fElements[aSourceIndex];
	fElements[aSourceIndex] = fElements[aTargetIndex];
	fElements[aTargetIndex] = lBuffer;
}

void IntVector::sort(const IntSorter& aSorter) {
	aSorter(*this);
}

const int IntVector::operator[](size_t aIndex) const {
	if (aIndex < 0 || aIndex >= fNumberOfElements) {
		throw out_of_range("Illegal Vector Index.");
	}

	return fElements[aIndex];
}

IntVectorIterator IntVector::begin() const {
	return IntVectorIterator (*this);
}

IntVectorIterator IntVector::end() const {
	return IntVectorIterator(*this, size());
}