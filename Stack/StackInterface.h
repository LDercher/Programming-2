/**
*	@file : StackInterface.h
*	@author: Luke Dercher
*	@date: 2015.02.27
*	@purpose: Pure virtual interface for the derived stack class
*/

#ifndef STACK_INTERFACE
#define STACK_INTERFACE
#include<stdexcept>
#include"PreconditionViolationException.h"
#include"node.h"

template <typename T>

class StackInterface
{


public:
	
	/**
	* @pre A derived class from StackInterface has been instantiated, and the derived class has redifined the destructor.
`	* @post The entire contents of the stack have been deleted	
	*/
	virtual ~StackInterface() {};

	/**
	* @pre A derived stack class has been instantiated and the number of nodes in it has ben properly incremented and decremeted
	* @post the value of of the number of nodes in the stack is not changed
	* @return bool value depeding of whether the size value of the stack is zero or not
	*/
    virtual bool isEmpty() const = 0;

	/**
	* @pre A derived class from StackInterface has been instantiated.	
	* @post The other nodes in the stack have been moved accordingly to make the new node created by push at the top of the stack
	* @return A new node at the top of the stack
	*/
	virtual void push(const T newEntry) = 0;

	/**
	* @pre Assumes the stack is not empty
	* @post properly adujusts the poitners in the stack to reflect the top has been removed. Throws PVE if stack is empty.
	* @return The value contained by the top node
	*/
    virtual T pop() throw(PreconditionViolationException)= 0;

	/**
	*  @pre Assumes the stack is not empty
	*  @post the value being displayed is not altered in any way
	*  @return the value, conatined in the node, at the top of the stack. Throws PVE if stack is empty.
	*/
    virtual T peek() const throw(PreconditionViolationException)= 0;

	/**
	* @pre Assumes the value that contains the size of the stack has been proerly incremented and decremented
	* @post The size value of the stack is left unchanged
	* @return the size value of the stack
	*/	
	virtual int size() const = 0;

	/**
	* @pre A derived class from StackInterface has been instantiated.
	* @post leaves the derived stack object unchanged
	* @return The values of the stack printed in a list
	*/
	virtual void print() const=0;

	/**
 	* @pre Assumes two instances of a derived class have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is less than the right hand side
	*/
    virtual bool operator < (const StackInterface<T>& rhs) const=0;

	/**
 	* @pre Assumes two instances of a derived class have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is less than or equal to the right hand side
	*/
	virtual bool operator <= (const StackInterface<T>& rhs) const=0;

	/**
 	* @pre Assumes two instances of a derived class have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is greater than the right hand side
	*/
	virtual bool operator > (const StackInterface<T>& rhs) const=0;

	/**
 	* @pre Assumes two instances of a derived class have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size is greater than or equal to the right hand side
	*/
	virtual bool operator >= (const StackInterface<T>& rhs) const=0;

	
	/**
 	* @pre Assumes two instances of a derived class have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size equal to the right hand side
	*/
	virtual bool operator == (const StackInterface<T>& rhs) const=0;

	/**
 	* @pre Assumes two instances of a derived class have been instantiated.
	* @post The two stack instances are left unchanged 
	* @return A bool value indicating whether the stack's size isn't equal to the right hand side
	*/
	virtual bool operator != (const StackInterface<T>& rhs) const=0;

};
#endif //StackInterface.h
