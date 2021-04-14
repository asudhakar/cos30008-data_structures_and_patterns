#include "IntVector.h"
#include "IntVectorIterator.h"

IntVectorIterator::IntVectorIterator(const IntVector& aContainer, size_t aStart) : fContainer(aContainer), fPosition(aStart) {

}

const int IntVectorIterator::operator*() const {
	return fContainer[fPosition];
}

IntVectorIterator& IntVectorIterator::operator++() {
	fPosition++;
	return *this;
}

IntVectorIterator IntVectorIterator::operator++(int) {
	IntVectorIterator old = *this;
	++(*this);
	return old;
}

bool IntVectorIterator::operator==(const IntVectorIterator& aRHS) const {
	return
		&fContainer == &aRHS.fContainer &&
		fPosition == aRHS.fPosition;
}

bool IntVectorIterator::operator!=(const IntVectorIterator& aRHS) const {
	return !(*this == aRHS);
}

IntVectorIterator IntVectorIterator::begin() const {
	IntVectorIterator iter = *this;

	iter.fPosition = 0;
	return iter;
}

IntVectorIterator IntVectorIterator::end() const {
	IntVectorIterator iter = *this;

	iter.fPosition = iter.fContainer.size();
	return iter;
}