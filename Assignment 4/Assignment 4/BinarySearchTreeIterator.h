
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
    
	BinarySearchTreeIterator(const BNode<T>* aBNodeTree) 
		: fBNodeTree(aBNodeTree)
	{
		if (!fBNodeTree->empty())
		{
			fStack.push(fBNodeTree);

			while (!fStack.top()->left->empty()) {
				fStack.push(fStack.top()->left);
				fBNodeTree = fBNodeTree->left;
			}
			fStack.pop();
		}
	}

	const T& operator*() const {
		return fBNodeTree->key;
	}

	Iterator& operator++() {
		if (fStack.empty())
			fBNodeTree = &BNode<T>::NIL;
		
		else {
			fBNodeTree = fStack.top();
			fStack.pop();
			if (!fBNodeTree->right->empty()) {
				fStack.push(fBNodeTree->right);
				while (!fStack.top()->left->empty())
					fStack.push(fStack.top()->left);
			}
		}

		return *this;
	}
	Iterator operator++(int) {
		Iterator temp = Iterator(*this);
		++(*this);
		return temp;
	}

	bool operator==(const Iterator& aOtherIter) const {
		return fBNodeTree->key == aOtherIter.fBNodeTree->key;
	}
	bool operator!=(const Iterator& aOtherIter) const {
		return fBNodeTree->key != aOtherIter.fBNodeTree->key;
	}
    
	Iterator begin() const {
		return Iterator(fStack.top());
	}
	Iterator end() const {
		return Iterator(&BNode<T>::NIL);
	}
};
