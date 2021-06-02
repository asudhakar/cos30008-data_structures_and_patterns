#pragma once

#include <iostream>

template<class T>
class TreeVisitor
{
public:
	virtual ~TreeVisitor(){}

	//default behavior
	virtual void preVisit(const T& aKey) const {}
	virtual void postVisit(const T& aKey) const {}
	virtual void inVisit(const T& aKey) const {}
	virtual void visit(const T& aKey) const {
		std::cout << " " << aKey;
	}

	void emitNIL() const {
		std::cout << " []";
	}
};