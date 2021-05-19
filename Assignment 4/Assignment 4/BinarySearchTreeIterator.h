
// COS30008, Problem Set 4, 2021

#pragma once

#include <stack>

#include "BNode.h"

template<typename T>
class BinarySearchTreeIterator
{
private:
    const BNode<T>* fBNodeTree;				// binary search tree
    std::stack<const BNode<T>*> fStack;		// DFS traversal stack
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;
    
	BinarySearchTreeIterator( const BNode<T>* aBNodeTree );

	const T& operator*() const;

	Iterator& operator++();
	Iterator operator++(int);

	bool operator==( const Iterator& aOtherIter ) const;
	bool operator!=( const Iterator& aOtherIter ) const;
    
	Iterator begin() const;
	Iterator end() const;
};
