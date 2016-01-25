/**
*	@file : stack.h
*	@author: Luke Dercher
*	@date: 2015.03.22
*	@purpose: .h file for stack class. Creates the structure in which our data will be placed in.
*/

#ifndef STACK_H
#define STACK_H
#include<stdexcept>
#include"PreconditionViolationException.h"
#include"node.h"
#include "StackInterface.h"

template <typename T>

class Stack: public StackInterface<T>

{
protected:



    int m_size;

public:

        node<T>* m_top;

    /**
    * @pre none
    * @post Initializes a new stack with m_size set to 0 and m_top set to nullptr
    * @return initialized stack
    */
    Stack();

    /**
    * @pre A stack has been initialized and populated with nodes
    * @post deletes all nodes in the stack
    * @return n/a
    */
    ~Stack();

    /**
    * @pre A stack has been initialized.
    * @post the stack is left unchanged
    * @return A bool value reflecting whether the stack is empty or not
    */
    bool isEmpty() const;

    /**
    * @pre A stack has been initialized.
    * @post A node with the specified T value is placed on top of the stack, and pointers are moved correctly. M_size is incremeneted.
    * @return n/a
    */
    void push (const T& newEntry);

    /**
    * @pre Assumes the stack is not empty
    * @post Removes the node at the top of the stack and changes pointers accordingly. Throw PVE if stack is empty. Decrements m_size.
    * @return T value contained in the node that is removed. If PVE is thrown, no value is returned.
    */
    T pop () throw(PreconditionViolationException);

    /**
    * @pre Assumes the stack is not empty
    * @post All nodes are left unchanged. Throw PVE if stack is empty.
    * @return T value contained in the node at the top of the stack. If PVE is thrown, no value is returned.
    */
    T peek () const throw(PreconditionViolationException);

    /**
    * @pre Assumes a stack has been initialized.
    * @post Value m_size is left unchanged.
    * @return m_size
    */
    int size() const;




};

#include "stack.hpp"

#endif // STACK_H
