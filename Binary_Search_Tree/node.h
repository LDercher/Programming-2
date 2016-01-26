/**
*	@file : node.h
*	@author: Luke Dercher
*	@date: 2015.04.11
*	@purpose: Node class for nodes that will fill a binary serach tree. w/ a left pointer and right pointer
*/

#ifndef NODE_H
#define NODE_H


template <typename T>

class Node
{
private:

    Node<T>* m_left;

    Node<T>* m_right;

    T m_value;

public:


    /**
    * @post Constructor for node class, Sets m_right and m_left to nullptr and leaves m_value alone since it's templated.
    */
    Node();

    /**
    * @post Node copy constructor. Creates a deep copy of the other node. (meaning it also creates copies of what other points to)
    */
    Node (const Node<T>& other);

    /**
    * @return The T value of the node.
    */
    T getValue();

    /**
    * @return A pointer to the left node.
    */
    Node<T>* getLeft();

    /**
    * @return A pointer to the right node.
    */
    Node<T>* getRight();

    /**
    * @post Sets the value of the node.
    */
    void setValue(T value);

    /**
    * @post Sets m_left
    */
    void setLeft(Node<T>* left);

    /**
    * @post Se3ts m_right
    */
    void setRight(Node<T>* right);


};

#include "node.hpp"

#endif // NODE_H
