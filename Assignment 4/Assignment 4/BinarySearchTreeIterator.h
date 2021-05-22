
// COS30008, Problem Set 4, 2021

#pragma once

#include <stack>
#include <iostream>

#include "BNode.h"

template<typename T>
class BinarySearchTreeIterator
{
private:
    const BNode<T>* fBNodeTree;				// binary search tree
    std::stack<const BNode<T>*> fStack;		// DFS traversal stack
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;
    
	BinarySearchTreeIterator(const BNode<T>* aBNodeTree) 
		: fBNodeTree(aBNodeTree)
	{
		if (!fBNodeTree->empty())
		{
			fStack.push(fBNodeTree);

			while (!fStack.top()->left->empty())
				fStack.push(fStack.top()->left);
		}
		std::cout << fStack.top() << endl;
	}

	const T& operator*() const {
		return fBNodeTree->key;
	}

	Iterator& operator++() {
		/*
		If the current node has a non-null right child,
			Take a step down to the right
			Then run down to the left as far as possible

		If the current node has a null right child,
			move up the tree until we have moved over a left child link*/

		if (!fBNodeTree->empty() || !fStack.empty())
		{
			while (fBNodeTree != NULL)
			{
				fStack.push(fBNodeTree);
				fBNodeTree = fBNodeTree->left;
			}

			fBNodeTree = fStack.top();
			fStack.pop();

			std::cout << fBNodeTree->key << " ";
			fBNodeTree = fBNodeTree->right;
		}
		return *this;
	}
	Iterator operator++(int) {
		Iterator iter = *this;
		return iter;
	}

	bool operator==(const Iterator& aOtherIter) const {
		return fBNodeTree->key == aOtherIter.fBNodeTree->key;
	}
	bool operator!=(const Iterator& aOtherIter) const {
		return fBNodeTree->key != aOtherIter.fBNodeTree->key;
	}
    
	Iterator begin() const {
		return Iterator(fBNodeTree->findMin());
	}
	Iterator end() const {
		return Iterator(&BNode<T>::NIL);
	}
};
