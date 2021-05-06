
// COS30008, List, Problem Set 3, 2021

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;
template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot;	// the first element in the list
	size_t fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;

	~List()                                                             // destructor - frees all nodes
    {
        while ( fRoot != nullptr )
        {
            if ( fRoot != &fRoot->getPrevious() )                       // more than one element
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last
                
                lTemp->isolate();                                       // remove from list
                delete lTemp;                                           // free
            }
            else
            {
                delete fRoot;                                           // free last
                break;                                                  // stop loop
            }
        }
    }

    void remove( const T& aElement )	                                // remove first match from list
    {
        Node* lNode = fRoot;                                            // start at first
        
        while ( lNode != nullptr )                                      // Are there still nodes available?
        {
            if ( **lNode == aElement )                                  // Have we found the node?
            {
                break;                                                  // stop the search
            }

            if ( lNode != &fRoot->getPrevious() )                       // not reached last
            {
                lNode = const_cast<Node*>(&lNode->getNext());           // go to next
            }
            else
            {
                lNode = nullptr;                                        // stop search
            }
        }
        
        // At this point we have either reached the end or found the node.
        if ( lNode != nullptr )                                         // We have found the node.
        {
            if ( fCount != 1 )                                          // not the last element
            {
                if ( lNode == fRoot )
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
                }
            }
            else
            {
                fRoot = nullptr;                                        // list becomes empty
            }
            
            lNode->isolate();                                           // isolate node
            delete lNode;                                               // release node's memory
            fCount--;                                                   // decrement count
        }
    }

	// PS3 starts here
    
	// P1

    List() : fRoot(nullptr), fCount(0) {}                          // default constructor

    bool isEmpty() const	                    						// Is list empty?
    {
        return fRoot == nullptr;
    }

    size_t size() const                					    			// list size
    {
        return fCount + 1;
    }

    void push_front(const T& aElement)	    			    			// adds aElement at front
    {
        if (isEmpty()) {
            fRoot = new Node(aElement);
            return;
        }
        Node* lNodeInsert = new Node(aElement);
        *fRoot->push_front(*lNodeInsert);
        fRoot = lNodeInsert;
        fCount++;
    }

    Iterator begin() const                       						// return a forward iterator
    {
        Iterator iter(fRoot);
        return iter.begin();
    }

    Iterator end() const                           						// return a forward end iterator
    {
        Iterator iter(fRoot);
        return iter.end();
    }

    Iterator rbegin() const                     						// return a backwards iterator
    {
        Iterator iter(fRoot);
        return iter.rbegin();
    }

    Iterator rend() const                      						    // return a backwards end iterator
    {
        Iterator iter(fRoot);
        return iter.rend();
    }

	// P2

    void push_back(const T& aElement)              						// adds aElement at back
    {
        if (isEmpty()) {
            fRoot = new Node(aElement);
            return;
        }
        Node* lNodeInsert = new Node(aElement);
        const_cast<Node*>(&fRoot->getPrevious())->push_back(*lNodeInsert);
        fCount++;
    }

	// P3

    const T& operator[](size_t aIndex) const							// list indexer
    {
        if (aIndex > fCount) {
            throw range_error("Index is out of range.");
        }

        Node* lCurrentNode = fRoot;
        int lCount = 0;
        while (lCurrentNode != nullptr)
        {
            if (lCount == aIndex)
                return lCurrentNode->getPayload();
            lCount++;
            lCurrentNode = const_cast<Node*>(&lCurrentNode->getNext());
        }
    }

	// P4
    // copy constructor
    List(const List& aOtherList) : fRoot(nullptr), fCount(0) 
    {
        for (size_t i = 0; i < aOtherList.size(); i++)
        {
            push_back(aOtherList[i]);
        }
    }

    List& operator=(const List& aOtherList)     						// assignment operator
    {
        List<T> lTemp(aOtherList);

        Node* lCurrentNode = fRoot;
        size_t lCount = 0;
        size_t lMax = size() >= aOtherList.size() ? size() : aOtherList.size();

        while (lCurrentNode != nullptr)
        {
            if (lCount == lMax)
                break;

            if (lCount > fCount) {                                      // add new nodes if short on nodes
                push_back(aOtherList[lCount]);
            }
            else if (lCount > aOtherList.size() - 1) {                  // remove nodes if there are excess
                remove(lCurrentNode->getPayload());
            }
            else {
                Node* lNewNode = new Node(aOtherList[lCount]);          // swap payloads if on same position
                lCurrentNode->swap(*lNewNode);
            }

            lCount++;
            lCurrentNode = const_cast<Node*>(&lCurrentNode->getNext());
        }

        return *this;
    }
    
	// P5X

	// move features
	List( List&& aOtherList );                 							// move constructor
	List& operator=( List&& aOtherList );       						// move assignment operator
    void push_front(T&& aElement)               						// adds aElement at front
    {
        push_front(std::move(aElement));
    }
    void push_back(T&& aElement)               	    					// adds aElement at back
    {
        push_back(std::move(aElement));
    }
};
