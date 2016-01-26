/**
*	@file : binarysearchtree.hpp
*	@author: Luke Dercher
*	@date: 2015.04.11
*	@purpose: Implementation of BinarySearchTree class.
*/

#include "binarysearchtree.h"


template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{

    if (other.isEmpty())
    {
        m_root = nullptr;
        return;
    }
    else
    {
        m_root = new Node<T>(*(other.m_root));
    }
}


template <typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{
    BSTI<T>*  temp=  new BinarySearchTree(*(this));

    return temp;
}

template <typename T>
T BinarySearchTree<T>::addAll(Node<T>* subTree)
{

    if (subTree == nullptr)
    {
        return 0;
    }

    return subTree->getValue() + addAll(subTree->getLeft()) + addAll(subTree->getRight());


}

template <typename T>
T BinarySearchTree<T>::addAll()
{

    return addAll(m_root);


}

template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subTree)
{

    if (value < subTree->getValue() )
    {
        if (subTree->getLeft()==nullptr)
        {
            Node<T>* temp = subTree->getLeft();

            temp = new Node<T>();

            temp->setValue(value);

            subTree->setRight(temp);

            return true;
        }
        else
        {
            add(value, subTree->getLeft());
        }
    }
    else if (value > subTree->getValue() )
    {
        if (subTree->getRight()==nullptr)
        {
            Node<T>* temp = subTree->getRight();

            temp = new Node<T>();

            temp->setValue(value);

            subTree->setRight(temp);

            return true;
        }
        else
        {
            add(value, subTree->getRight());
        }
    }
    return false;
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{

    if(subTree->getLeft() != nullptr)
    {
        deleteTree(subTree->getLeft());
    }
    if(subTree->getRight() != nullptr)
    {
        deleteTree(subTree->getRight());
    }
    delete subTree;

}

template <typename T>
T BinarySearchTree<T>::search(T value, Node<T> *subTree) const throw (ValueNotFoundException)
{
    if (subTree != nullptr)
    {
        if (value == subTree->getValue())
        {
            return value;
        }
        else if (value < subTree->getValue())
        {
            search(value, subTree->getLeft());
        }
        else
        {
            search(value, subTree->getRight());
        }
    }
   else
   {
        throw (ValueNotFoundException("Value not found in tree"));
   }

}

template <typename T>
T BinarySearchTree<T>::search(T value) const throw(ValueNotFoundException)
{

   return search(value, m_root);
}


template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subTree, Order order) const
{
    if (subTree == nullptr) return;

    switch (order)
    {
    case Order::PRE_ORDER:
            std::cout<<subTree->getValue()<<" ";

            printTree(subTree->getLeft(), order);

            printTree(subTree->getRight(),order);

            break;

     case 1:
            printTree(subTree->getLeft(), order);

            std::cout<<subTree->getValue()<<" ";

            printTree(subTree->getRight(),order);

            break;

     case 2:
            printTree(subTree->getLeft(), order);

            printTree(subTree->getRight(),order);

            std::cout<<subTree->getValue()<<" ";

            break;
     }

}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    //uses delete tree method

    BinarySearchTree<T>::deleteTree(m_root);
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
    if (m_root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template <typename T>
bool BinarySearchTree<T>::add(T value)
{
    if(m_root == nullptr)
    {
        Node<T>* temp = new Node<T>();

        temp->setValue(value);

        m_root = temp;

        return true;
    }
    else
    {
        return add(value, m_root);

    }
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order)const
{
    printTree(m_root, order);
}

template <typename T>
void BinarySearchTree<T>::sortedPrint() const
{
    printTree(IN_ORDER);
}
