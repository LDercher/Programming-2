  /**
*	@file : doublell.hpp
*	@author :  Luke Dercher
*	@date : 2015.02.15
*	Purpose: Implementation file of templated Double linked list Class.
*/


#include "doublell.h"
#include "node.h"
#include <iostream>
#include <stdexcept>


template <typename T>
DoubleLL<T>::DoubleLL()
{
    m_size = 0;

    m_front = nullptr;

    m_back = nullptr;
}

template <typename T>
DoubleLL<T>::~DoubleLL()
{
    node<T>* temp = nullptr;
    while (m_size != 0)
    {
        if (m_size == 1)
        {
             delete m_front;

             m_front = nullptr;

             m_back = nullptr;

             m_size--;

        }
        else if (m_size > 1)
        {
            temp = m_front;

            m_front = m_front -> getNext();

            delete temp;

            m_size--;

        }

    }
}


template <typename T>
node<T>* DoubleLL<T>::dupsFound()
{
    node<T>* temp1 = m_front;

    node<T>* temp2  = temp1->getNext();

    while (temp1->getNext() != nullptr)
    {
        while(temp2 != nullptr)
        {
            if (temp1->getValue() == temp2->getValue())
            {
               return temp2;
            }

            temp2 = temp2->getNext();
        }

        temp1 = temp1->getNext();

        temp2 = temp1->getNext();
    }

    return nullptr;
}

template <typename T>
void DoubleLL<T>::removeDups()
{
    if(dupsFound() != nullptr)
    {
        removePointer(dupsFound());

        removeDups();
    }
}




template <typename T>
void DoubleLL<T>::removePointer(node<T>* remove)
{

    if(remove == nullptr)
    {
        return;
    }
    else if (remove==m_front && remove==m_back)
    {
        m_front = nullptr;

        m_back = nullptr;

        delete remove;

        m_size--;

    }
    else if(remove == m_front)
    {
        m_front = m_front->getNext();

        m_front -> setPrev(nullptr);

        delete remove;

        m_size--;

    }
    else if (remove == m_back)
    {
        m_back = m_back->getPrev();

        m_back ->setNext(nullptr);

        delete remove;

        m_size--;

    }
    else
    {
        node<T>* Prev = remove->getPrev();

        node<T>* Next = remove->getNext();

        Prev->setNext(Next);

        Next->setPrev(Prev);

        delete remove;

        m_size--;

    }

}



template <typename T>
bool DoubleLL<T>::isEmpty() const
{
    if (m_size > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
int DoubleLL<T>::GetSize() const
{
    return m_size;
}

template <typename T>
void DoubleLL<T>::pushFront(T value)
{
    if (m_size == 0)
    {
        m_back = new node<T>;

        m_back -> setValue(value);

        m_front = m_back;
    }
    else
    {
        node<T>* temp = new node<T>;

        temp -> setValue(value);

        temp ->setPrev(nullptr);

        temp->setNext(m_front);

        m_front ->setPrev(temp);

        m_front=temp;

    }

 m_size ++;

}


template <typename T>
void DoubleLL<T>::pushBack(T value)
{
    if (m_size == 0)
    {
        m_back = new node<T>;

        m_back -> setValue(value);

        m_front = m_back;
    }
    else
    {
        node<T>* temp = new node<T>;

        temp -> setValue(value);

        temp ->setPrev(m_back);

        temp ->setNext(nullptr);

        m_back ->setNext(temp);

        m_back = temp;


    }

    m_size++;
}

template <typename T>
bool DoubleLL<T>::remove(T value)
{

    node<T>* temp = find(value);

    if(temp == nullptr)
    {
        return false;
    }
    else if (temp==m_front && temp==m_back)
    {
        m_front = nullptr;

        m_back = nullptr;

        delete temp;

        m_size--;

        return true;
    }
    else if(temp == m_front)
    {
        m_front = m_front->getNext();

        m_front -> setPrev(nullptr);

        delete temp;

        m_size--;

        return true;
    }
    else if (temp == m_back)
    {
        m_back = m_back->getPrev();

        m_back ->setNext(nullptr);

        delete temp;

        m_size--;

        return true;
    }
    else
    {
        node<T>* tempPrev = temp->getPrev();

        node<T>* tempNext = temp->getNext();

        tempPrev->setNext(tempNext);

        tempNext->setPrev(tempPrev);

        delete temp;

        m_size--;

        return true;
    }





}

template <typename T>
void DoubleLL<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
    node<T>* temp = find(listValue);

    if (temp == nullptr)
    {
        throw (std::runtime_error ("value is not in the list"));
    }
    else if (temp==m_front && temp==m_back)
    {
        m_front = new node<T>;

        m_front->setValue(newValue);

        m_front->setNext(m_back);

        m_back ->setPrev(m_front);

        m_back ->setNext(nullptr);

        m_front ->setPrev(nullptr);

        m_size++;
    }
    else if(temp == m_front)
    {
        temp = new node<T>;

        temp->setValue(newValue);

        m_front->setPrev(temp);

        temp->setNext(m_front);

        temp->setPrev(nullptr);

        m_front = temp;

        m_size++;
    }
    else if(temp == m_back)
    {
        temp = new node<T>;

        temp->setValue(newValue);

        m_back->setNext(temp);

        temp->setPrev(m_back);

        temp->setNext(nullptr);

        m_back = temp;

        m_size++;
    }
    else
    {
        node<T>* tempNew = new node<T>;

        tempNew->setValue(newValue);

        node<T>* tempNext = temp->getNext();

        tempNew->setPrev(temp);

        tempNew->setNext(tempNext);

        temp->setNext(tempNew);

        tempNext->setPrev(tempNew);

        m_size++;

    }

}

template <typename T>
void DoubleLL<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
    node<T>* temp = find(listValue);

    if (temp == nullptr)
    {
        throw (std::runtime_error ("value is not in the list"));
    }
    else if (temp==m_front && temp==m_back)
    {
        m_back = new node<T>;

        m_front->setValue(newValue);

        m_front->setNext(m_back);

        m_back ->setPrev(m_front);

        m_back->setNext(nullptr);

        m_front->setPrev(nullptr);

        m_size++;
    }
    else if(temp == m_front)
    {
        temp=new node<T>;

        temp->setValue(newValue);

        m_front->setPrev(temp);

        temp->setNext(m_front);

        temp->setPrev(nullptr);

        m_front= temp;

        m_size++;

    }
    else if(temp == m_back)
    {
        temp = new node<T>;

        temp->setValue(newValue);

        m_back->setNext(temp);

        temp->setNext(nullptr);

        temp->setPrev(m_back);

        m_back = temp;

        m_size++;
    }
    else
    {
        node<T>* tempNew = new node<T>;

        tempNew->setValue(newValue);

        node<T>* tempPrev = temp->getPrev();

        tempNew->setNext(temp);

        tempNew->setPrev(tempPrev);

        temp->setPrev(tempNew);

        tempPrev->setNext(tempNew);

        m_size++;

    }

}



template <typename T>
node<T>* DoubleLL<T>::find(T value) const
{
    node<T>* temp = m_front;

     while (temp!= nullptr)
     {
          if (temp->getValue() == value)
          {

              return temp;

          }

          temp = temp->getNext();
     }

     return nullptr;

}

template <typename T>
void DoubleLL<T>::printList() const
{
    if (m_size == 0)
    {
        std::cout << "List empty";
    }
    else
    {
        node<T>* temp = m_front;


        while (temp  != nullptr)
        {

            std::cout << temp->getValue();

            if(temp->getNext()  != nullptr)
            {
                std::cout<<",";
            }

            temp = temp ->getNext();

        }

    }
}
