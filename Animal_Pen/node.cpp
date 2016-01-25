/**
*	@file : node.cpp
*	@author :  Luke Dercher
*	@date : 2015.02.05
*	Purpose: Implementation of node Class.
*/



template <typename T>
node<T>::node()
{
    m_value = T();

    m_next = nullptr;
}

template <typename T>
void node<T>::setValue(T value)
{
    m_value = value;
}

template <typename T>
T node<T>::getValue()
{
    return m_value;
}

template <typename T>
void node<T>::setNext(node<T>* prev)
{
    m_next = prev;
}

template <typename T>
node<T>* node<T>::getNext()
{
    return m_next;
}
