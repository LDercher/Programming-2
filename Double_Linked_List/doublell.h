/**
*	@file : doublell.h
*	@author :  Luke Dercher
*	@date : 2015.02.15
*	Purpose: Header file of templated Double linked list Class.
*/

#ifndef DOUBLELL_H
#define DOUBLELL_H
#include <stdexcept>


template <typename T>
class DoubleLL
{
private:

        node<T>* m_front;

        node<T>* m_back;

        int m_size;

public:

        /**
        *  @pre A node class has been created with an m_next and m_prev point
        *  @post Creates and initializes a double linked list
        *  @return Initialzed linked list with m_size set to 0 and m_front set to null pointer and m_back set to null pointer
        */
        DoubleLL();


        /**
        *  @pre A double liked list has been created and popluted with nodes
        *  @post none
        *  @return Clears double liknked list fo all nodes
        */
        ~DoubleLL();

        /**
        *  @pre A double linked list has been initialized and m_size has been initialized to zero and then incremented and decremented approprialty.
        *  @post none
        *  @return true or false depending on wheter m_size is zero or anothe value
        */
        bool isEmpty() const;

        /**
        *  @pre m_size has been initialized to zero and then properly incremented or decremented
        *  @post none
        *  @return the value of m_size
        */
        int GetSize() const;

        node<T>* dupsFound();

        void removePointer(node<T>* node);

        void removeDups();

        /**
        *  @pre A double linked list has been initialized and a node class has been written with an m_next and m_prev pointer
        *  @post m_size has been initialized.
        *  @return a new node with value T stored in it. Placed in the front to the double linked list.
        */
        void pushFront(T value);

        /**
        *  @pre A double linked list has been initialized and a node class has been written with an m_next and m_prev pointer
        *  @post m_size has been initialized.
        *  @return a new node with value T stored in it. Placed at the end of the double linked list.
        */
        void pushBack(T value);

        /**
        *  @pre A double linked list has been initialized and a node class has been written with an m_next and m_prev pointer
        *  @post there exists a T value in every node which is accessible with a getValue() method
        *  @return removes node containing user specified value otherwise throws a runtime error
        */
        bool remove(T value);

        /**
        *  @pre A double linked list has been initialized and populated with at least one node
        *  @post the list value is contained within a node in the list .
        *  @return a new node with value T newValue stored in it. Placed in the front of the node containing the list value.
        */
        void insertAhead(T listValue, T newValue) throw (std::runtime_error);

        /**
        *  @pre A double linked list has been initialized and populated with at least one node
        *  @post the list value is contained within a node in the list .
        *  @return a new node with value T newValue stored in it. Placed behind of the node containing the list value.
        */
        void insertBehind (T listValue, T newValue) throw (std::runtime_error);

        /**
        *  @pre Assumes T is comparable with ==
        *  @post the list value is contained within a node in the list .
        *  @return a pointer to the node containing T value
        */
        node<T>* find(T value) const;

        /**
        *  @pre A double linked list has been initialized and populated with at least one node
        *  @post  teh type T is overloaded to be printable with the << operator
        *  @return a new node with value T newValue stored in it. Placed behind of the node containing the, user specified, list value.
        */
        void printList() const;



};

#include "doublell.hpp"
#endif // DOUBLELL_H
