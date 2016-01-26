/**
*	@file : binarysearchtree.h
*	@author: Luke Dercher
*	@date: 2015.04.11
*	@purpose: BinarySearchTree class used to store data and easily search for it.
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include"BSTI.h"
#include "node.h"
#include <iostream>
#include "valuenotfoundexception.h"

template <typename T>

class BinarySearchTree : public BSTI<T>
{
private:
    Node<T>* m_root;

    /**
    * @post Adds the correct value to the appropriate position in the properly ordered binary search tree.
    */
    bool add (T value, Node<T>* subTree);

    /**
    * @post Deletes the left subtree and right subtree of the node the pointer passed in is pointing to.
    */
    void deleteTree(Node<T>* subTree);

    /**
    * @return The T value if it exists in the tree. Throws exception if not found.
    */
    T search(T value, Node<T>* subTree) const throw(ValueNotFoundException);

    /**
    * @post prints the tree in the specified order
    */
    void printTree(Node<T>* subTree, Order order) const;

    T addAll(Node<T>* subTree);


public:

    /**
    * @post sets m_root to nullptr
    */
    BinarySearchTree();

    /**
    * @post creates a deep copy of the other BST
    */
    BinarySearchTree(const BinarySearchTree<T>& other);

    /**
    * @post BST destructor
    */
    ~BinarySearchTree();

    /**
    * @post Creates a deep copy of this
    * @return A pointer to the deep copy of this
    */
    BSTI<T>* clone();

    /**
    * @pre this is in a valid state
    * @post Creates a deep[ copy of this
    * @return true if no nodes in the tree, false otherwise
    */
    bool isEmpty() const;

    /**
    * @post adds a node containing the value in the tree
    * @return true if addition operation was successful (DUPLICATE COPIES WILL NEVER BE ADDED TO TE TREE)
    */
    bool add(T value);

    T addAll();


    /**
    * @post If the tree is empty display "Tree Empty" Otherwise print the tree in the specified order
    */
    void printTree(Order order) const;

    /**
    * @post The contents of the tree are posted IN_ORDER
    */
    void sortedPrint() const;

    /**
    * @return The result from search(T value, Node<T>* saubtree). Throws excepion of not found.
    */
    T search(T value) const throw (ValueNotFoundException);

};

#include "binarysearchtree.hpp"

#endif // BINARYSEARCHTREE_H
