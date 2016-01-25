/**
*	@file : node.h
*	@author :  Luke Dercher
*	@date : 2015.02.05
*	Purpose: header file of node Class.
*/

#ifndef NODE_H
#define NODE_H

template <typename T>

class node
{
private:

    T m_value;

    node<T>*  m_next;

public:

    /**
    *  @pre None
    *  @post Creates and initializes a node
    *  @return Initialzed node with m_value set to 0 and m_next set to null pointer
    */
    node();

    /**
    *  @pre m_value has been initialized to zero
    *  @post none
    *  @return a new vlue for m_value set by the user
    */
    void setValue (T value);

    /**
    *  @pre There exists an int called m_value that has been inititialized to something
    *  @post none
    *  @return the int value m_value
    */
    T getValue ();

    /**
    *  @pre There exists a  node
    *  @post none
    *  @return the int value m_value
    */
    void setNext (node<T>* prev);

    /**
    *  @pre none
    *  @post none
    *  @return m_next
    */
    node<T>* getNext();

    
    

};

#include "node.hpp"

#endif // NODE_H
