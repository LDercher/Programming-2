/**
*	@file : LinkedList.h
*	@author :  Luke Dercher
*	@date : 2015.02.05
*	Purpose: Header file of LinkedlList Class.
*/

#ifndef LINKEDLLIST_H
#define LINKEDLLIST_H
#include "node.h"
class linkedlist
{
private:

    node* m_front;

    int m_size;


public:

    /**
    *  @pre None
    *  @post Creates and initializes a LinkedList
    *  @return Initialzed LinkedList with m_   set to 0 and m_next set to null pointer
    */
    linkedlist();

    /**
    *  @pre There are nodes contained in the list
    *  @post none
    *  @return Deletes all nodes in the list
    */
    ~linkedlist();

    /**
    *  @pre A LinkedList has been created
    *  @post none
    *  @return True if the list is empty and false otherwise
    */
    bool isEmpty() const;

    bool deleteIndex(int index);

    /**
    *  @pre A list has been created that has the variable m_size that is incremented when an item is added to the list
    *  @post none
    *  @return The size of the list
    */
    int getSize() const;

    /**
    *  @pre A list of nodes has been created that contain int values
    *  @post none
    *  @return True if a node containing that int value is in the list
    */
    bool search(int value) const;

    /**
    *  @pre A LinkedList has been created
    *  @post Creates and initializes a node
    *  @return Prints the list to the consoleor the message "list Empty" if the list is empty
    */
    void printList() const;

    /**
    *  @pre A LinkedList has been created
    *  @post Adds one element to the back of the list
    *  @return none
    */
    void addBack (int value);

    /**
    *  @pre A LinkedList has been created
    *  @post Adds one element to the front of the list
    *  @return none
    */
    void addFront (int value);

    /**
    *  @pre A LinkedList has been created
    *  @post Removes one element to the back of the list
    *  @return True if the back element was removed and false if the list was empty
    */
    bool removeBack();

    /**
    *  @pre A LinkedList has been created
    *  @post Removes one element to the back of the list
    *  @return True if the back element was removed and false if the list was empty
    */
    bool removeFront();





};

#endif // LINKEDLLIST_H
