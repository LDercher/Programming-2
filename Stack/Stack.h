/**
*	@file : Stack.h
*	@author: Luke Dercher
*	@date: 2015.03.27
*	@purpose: A stack class derived from the StackInterface class.
*/

#ifndef STACK_H
#define STACK_H

#include"StackInterface.h"
#include"node.h"
#include <stdexcept>
#include<iostream>

template <typename T>

class Stack: public StackInterface<T>
{

private:
	
    node<T>* m_top;

	int m_size;

public: 
	
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
	virtual bool isEmpty() const;

	/**
	* @pre A stack has been initialized.
	* @post A node with the specified T value is placed on top of the stack, and pointers are moved corectly
	* @return n/a
	*/
	void push (const T newEntry);

	/**
	* @pre Assumes the stack is not empty
	* @post Removes the node at the top of the stack and changes pointers accordingly. Throw PVE if stack is empty.
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

	/**
	* @pre A stack has been initialized.
	* @post prints the content of the stack or "Stack Empty" if the stack is empty. The contents of the stack are left unchanged.
	* @return n/a
	*/
	void print () const;

	/**
 	* @pre Assumes two instances of a stack have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is less than the right hand side
	*/
    	bool operator < (const StackInterface<T>& rhs) const;

	/**
 	* @pre Assumes two instances of a stack have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is less than or equal to the right hand side
	*/
	bool operator <= (const StackInterface<T>& rhs) const;

	/**
 	* @pre Assumes two instances of a stack have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is greater than the right hand side
	*/
    bool operator > (const StackInterface<T>& rhs) const;

	/**
 	* @pre Assumes two instances of a stack have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is greater than or equal to the right hand side
	*/
    bool operator >= (const StackInterface<T>& rhs) const;

	
	/**
 	* @pre Assumes two instances of a stack have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size equal to the right hand side
	*/
    bool operator == (const StackInterface<T>& rhs) const;

	/**
 	* @pre Assumes two instances of a stack have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size isn't equal to the right hand side
	*/
    bool operator != (const StackInterface<T>& rhs) const;
};
#include"Stack.hpp"
#endif //STACK_H
