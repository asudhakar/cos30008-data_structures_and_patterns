
// COS30008, List, Problem Set 3, 2021

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <stdexcept>

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

    List() : fRoot(nullptr), fCount(0) {}                               // default constructor

    bool isEmpty() const	                    						// Is list empty?
    {
        return fRoot == nullptr;
    }

    size_t size() const                					    			// list size
    {
        return fCount;
    }

    void push_front(const T& aElement)	    			    			// adds aElement at front
    {
        fRoot->push_front(aElement);
    }

    Iterator begin() const                       						// return a forward iterator
    {

    }

    Iterator end() const                           						// return a forward end iterator
    {

    }

    Iterator rbegin() const                     						// return a backwards iterator
    {

    }

    Iterator rend() const                      						    // return a backwards end iterator
    {

    }

	// P2

	void push_back( const T& aElement );        						// adds aElement at back

	// P3

	const T& operator[]( size_t aIndex ) const;							// list indexer

	// P4
	
	List( const List& aOtherList );             						// copy constructor
	List& operator=( const List& aOtherList );  						// assignment operator
    
	// P5X

	// move features
	List( List&& aOtherList );                 							// move constructor
	List& operator=( List&& aOtherList );       						// move assignment operator
	void push_front( T&& aElement );            						// adds aElement at front
	void push_back( T&& aElement );             						// adds aElement at back
};
