/**
*	@file : LinkedList.cpp
*	@author :  Luke Dercher
*	@date : 2015.02.05
*	Purpose:  implementation of LinkedlList Class.
*/


#include "linkedlist.h"
#include "node.h"
#include <iostream>

linkedlist::linkedlist()
{
    m_front = nullptr;

    m_size = 0;
}

linkedlist::~linkedlist()
{
    while (m_size!=0)
    {
        removeFront();
    }
}

bool linkedlist::isEmpty() const
{
    if (m_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool linkedlist::deleteIndex(int index)
{
    int trav = 1;

    node* temp1 = m_front;

    node* temp2 = temp1->getNext();

    if (index == 1)
    {
        removeFront();

        return true;
    }
    else if (index > m_size)
    {
        return false;
    }
    else
    {
        while(trav < index-1)
        {
            trav++;

            temp1 = temp1->getNext();

            temp2 = temp2->getNext();
        }

        if (temp2->getNext() == nullptr)
        {
            removeBack();
        }
        else
        {
            temp1->setNext(temp2->getNext());

            delete temp2;
        }

        return true;
    }
}

int linkedlist::getSize() const
{
    return m_size;
}


bool linkedlist::search(int value) const
{
  node* temp = m_front;

   while (temp !=nullptr)
   {
        if (temp->getValue() == value)
        {

            return true;

        }

        temp = temp->getNext();
   }

   return false;

}

void linkedlist::printList() const
{
    if (m_size == 0)
    {
        std::cout << "List empty";
    }
    else
    {
        node* temp = m_front;

        std::cout << temp->getValue();

        while (temp ->getNext() != nullptr)
        {

            temp = temp ->getNext();

            std::cout << temp->getValue();

        }

    }
}


void linkedlist::addFront (int value)
{

    if (m_size == 0)
    {
        m_front = new node();

        m_front -> setValue(value);
    }
    else
    {
        node* temp = new node();

        temp -> setValue(value);

        temp ->setNext(m_front);

        m_front =temp;
    }

    m_size ++;

}

void linkedlist::addBack (int value)
{

    if (m_size == 0)
    {
        m_front = new node();

        m_front -> setValue(value);

    }
    else
   {

        node* temp1 = new node();

        node* temp2 = m_front;

        while (temp2 -> getNext() != nullptr)
        {
            temp2 = temp2 ->getNext();
        }

        temp1 ->setValue(value);

        temp2 -> setNext(temp1);
    }

    m_size++;

}

bool linkedlist::removeBack()
{
    if (m_size == 1)
    {
         removeFront();

         return true;

    }
    else if (m_size > 1)
    {
        node* secondToLast = m_front;

        node* last = m_front;

        while (last->getNext() != nullptr)
        {
            secondToLast = last;

            last = last -> getNext();
        }

        delete last;

        secondToLast -> setNext(nullptr);

        m_size --;

        return true;
    }
    else
    {
        return false;
    }


}



bool linkedlist::removeFront()
{
    if (m_size == 1)
    {
         delete m_front;

         m_front = nullptr;

         m_size--;

         return true;
    }
    else if (m_size > 1)
    {
        node* temp = m_front;

        m_front = m_front -> getNext();

        delete temp;

        m_size --;

        return true;
    }
    else
    {
        return false;
    }


}
