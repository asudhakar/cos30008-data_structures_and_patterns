#pragma once

#include <stdexcept>

template <class T>
class TTree
{
private:
    T fKey;
    TTree<T> *fLeft;
    TTree<T> *fMiddle;
    TTree<T> *fRight;

    TTree() : fKey() // use default constructor to initialise fKey
    {
        fLeft = &NIL; // loop-back: The sub-trees of a TTree object with no children point to NIL.
        fMiddle = &NIL;
        fRight = &NIL;
    }

    void addSubTree(TTree<T> **aBranch, const TTree<T> &aTTree)
    {
        if (*aBranch != &NIL)
        {
            delete *aBranch;
        }

        *aBranch = (TTree<T> *)&aTTree;
    }

    void removeSubTree(TTree<T> **aBranch) {
        if (*aBranch != &NIL)
        {
            delete *aBranch;
        }
    } // 14 marks

public:
    static TTree<T> NIL; // sentinel // 5 marks

    //TTree constructor (takes one argument) // 8 marks
    TTree(const T &aKey) : 
        fKey(aKey) 
    {
        fLeft = &NIL; // loop-back: The sub-trees of a TTree object with no children point to NIL.
        fMiddle = &NIL;
        fRight = &NIL;
    }

    // destructor (from sub-trees, must not free empty TTree) //15 marks
    ~TTree() {
        if (!isEmpty())
            delete this;
    }

    // copy-constructor, must not copy empty TTree // 20 marks
    TTree(const TTree<T> &aOtherTTree) :
        fKey()
    {
        if (!aOtherTTree.isEmpty())
            addSubTree(this, aOtherTTree);
    }

    // assignment operator, must not copy empty TTree // 20 marks
    TTree<T> &operator=(const TTree<T> &aOtherTTree) {
        if (this != aOtherTTree) {
            //delete
            delete this;
            //copy
            addSubTree(this, aOtherTTree);
        }
        return *this;
    }

    // clone TTree, must not copy empty TTree // 12 marks
    TTree<T> *clone() const {
        return new TTree(*this);
    }

    // return key value, may throw domain error if empty // 6 marks
    const T &getKey() const {
        if (!isEmpty())
            return fKey;
        throw(domain_error);
    }

    // returns true if this TTree is empty
    bool isEmpty() const {
        return fKey == NIL;
    }

    // getters for subtrees
    const TTree<T> &getLeft() const
    {
        return *fLeft;
    }

    const TTree<T> &getMiddle() const
    {
        return *fMiddle;
    }

    const TTree<T> &getRight() const
    {
        return *fRight;
    }

    // add a subtree
    void addLeft(const TTree<T> &aTTree)
    {
        addSubTree(&fLeft, aTTree);
    }

    void addMiddle(const TTree<T> &aTTree)
    {
        addSubTree(&fMiddle, aTTree);
    }

    void addRight(const TTree<T> &aTTree)
    {
        addSubTree(&fRight, aTTree);
    }

    // remove a subtree, may throw a domain error
    const TTree<T> &removeLeft()
    {
        return removeSubTree(&fLeft);
    }

    const TTree<T> &removeMiddle()
    {
        return removeSubTree(&fMiddle);
    }

    const TTree<T> &removeRight()
    {
        return removeSubTree(&fRight);
    }
};

template<class T>
TTree<T> TTree<T>::NIL;