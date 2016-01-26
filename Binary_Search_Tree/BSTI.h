/**
*	@file : BSTI.h
*	@author: Luke Dercher
*	@date: 2015.04.11
*	@purpose: Binary Search Tree interface class used to define how a binary search tree will be structured.
*/

#ifndef BSTI_H
#define BSTI_H

#include "valuenotfoundexception.h"

enum Order
{
    PRE_ORDER, IN_ORDER, POST_ORDER
};

template <typename T>

class BSTI
{
public:
    /**
    * @pre A BSTI exists
    * @post Deletes the entire tree
    */
    virtual ~BSTI(){};

    /**
    * @pre this is in a valid state
    * @post Creates a deep[ copy of this
    * @return a pointer to the deep copy of this
    */
    virtual BSTI<T>* clone() = 0;

    /**
    * @return true if no nodes in the tree. false if otherwise.
    */
    virtual bool isEmpty() const = 0;

    virtual T addAll() = 0;

    /**
    * @pre Vlue is a valid T value
    * @post a new Node<T> is created and inserted in the tree
    * @return false if the value coudn't be added (DUPLICATE VALUES ARE NOT ALLOWED IN THE TREE)
    */
    virtual bool add(T value) = 0;

    /**
    * @pre The type t is comparable with the == operator.
    * @return The T value if it exists in the tree, otherwise exception is thrown.
    */
    virtual T search(T value) const throw (ValueNotFoundException) = 0;

    /**
    * @post The contents of the tree are printed to the console in the specified order.
    */
    virtual void printTree(Order order) const = 0;

    /**
    * @post The contents of the tree are printed in IN_ORDER
    */
    virtual void sortedPrint() const = 0;



};





#endif // BSTI_H
