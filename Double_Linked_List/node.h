/**
*	@file : node.h
*	@author :  Luke Dercher
*	@date : 2015.02.15
*	Purpose: Header file of templated Double linked node Class.
*/

#ifndef NODE_H
#define NODE_H
#include <stdexcept>

template <typename T>
class node
{
private:

    node<T>* m_next;\

    node<T>* m_prev;

    T m_value;

public:

    /**
    *  @pre None
    *  @post Creates and initializes a node
    *  @return Initialzed node with m_value set to T() and m_next set to null pointer
    */
    node();

    /**
    *  @pre m_value has been initialized to zero
    *  @post sets a new value for for the node
    *  @return none
    */
    void setValue (T value);

    /**
    *  @pre There exists a value called m_value that has been inititialized to something
    *  @post none
    *  @return the int value m_value
    */
    T getValue ();

    /**
    *  @pre A node as been initialized
    *  @post sets the node<T>* to point to the next node in the list
    *  @return none
    */
    void setNext (node<T>* prev);

    /**
    *  @pre none
    *  @post none
    *  @return m_next
    */
    node<T>* getNext();

    /**
    *  @pre A node has been initialized
    *  @post none
    *  @return none
    */
    void setPrev (node<T>* next);

    /**
    *  @pre A node has been initialized
    *  @post none
    *  @return none
    */
    node<T>* getPrev();



};

#include "node.hpp"
#endif // NODE_H
