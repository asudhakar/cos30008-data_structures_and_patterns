
// COS30008, Problem Set 4, 2021

#pragma once

#include <stdexcept>
#include <iostream>

template<typename S>
struct BNode
{
    S key;
    BNode<S>* left;
    BNode<S>* right;
    
    static BNode<S> NIL;

    const S& findMax() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return right->empty() ? key : right->findMax();
    }

    const S& findMin() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return left->empty() ? key : left->findMin();
    }

    bool remove( const S& aKey, BNode<S>* aParent )
    {
        BNode<S>* x = this;
        BNode<S>* y = aParent;

        while ( !x->empty() )
        {
            if ( aKey == x->key )
            {
                break;
            }

            y = x;                                      // new parent
            
            x = aKey < x->key ? x->left : x->right;
        }

        if ( x->empty() )
        {
            return false;                               // delete failed
        }
        
        if ( !x->left->empty() )
        {
            const S& lKey = x->left->findMax();         // find max to left
            x->key = lKey;
            x->left->remove( lKey, x );
        }
        else
        {
            if ( !x->right->empty() )
            {
                const S& lKey = x->right->findMin();    // find min to right
                x->key = lKey;
                x->right->remove( lKey, x );
            }
            else
            {
                if ( y->left == x )
                {
                    y->left = &NIL;
                }
                else
                {
                    y->right = &NIL;
                }
                
                delete x;                               // free deleted node
            }
        }

        return true;
    }
    
	// PS4 starts here
    
    BNode() : key(NULL), left(&NIL), right(&NIL) {
    }
    BNode(const S& aKey) : key(aKey), left(&NIL), right(&NIL) {
    }
    BNode(S&& aKey) : key(aKey), left(&NIL), right(&NIL) {
    }

	~BNode() {
        if (!empty())
            remove(NULL, this);
    }
    
    bool empty() const {
        return this == &NIL;
    }
    bool leaf() const {
        return left == &NIL && right == &NIL;
    }

    size_t height() const {
        size_t lLeftHeight = -1;
        size_t lRightHeight = -1;

        if (!left->empty())
            lLeftHeight = left->height();

        if (!right->empty())
            lRightHeight = right->height();

        return max(lLeftHeight, lRightHeight) + 1;
    }

    bool insert(const S& aKey) {
        if (aKey == key || empty())
            return false;

        BNode<S>* x = this;
        if (aKey < key) {
            if (!x->left->empty())
                return x->left->insert(aKey);
            x->left = new BNode(aKey);
        }
        else {
            if (!x->right->empty())
                return x->right->insert(aKey);
            x->right = new BNode(aKey);
        }
    }
};

template<typename S>
BNode<S> BNode<S>::NIL;
