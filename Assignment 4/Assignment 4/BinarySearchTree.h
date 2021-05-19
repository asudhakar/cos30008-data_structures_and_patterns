
// COS30008, Problem Set 4, 2021

#pragma once

#include "BNode.h"

template<typename T>
class BinarySearchTreeIterator;

template<typename T>
class BinarySearchTree
{
private:
    BNode<T>* fRoot;
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;

	BinarySearchTree();
	~BinarySearchTree();

	bool empty() const;
    
	bool insert( const T& aKey );

	bool remove( const T& aKey );

	size_t height() const;
        
	Iterator begin() const;
	Iterator end() const;
};
