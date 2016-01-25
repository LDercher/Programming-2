/**
*	@file : node.cpp
*	@author :  Luke Dercher
*	@date : 2015.02.05
*	Purpose: Implementation of node Class.
*/


#include "node.h"

node::node()
{
    m_value = 0;

    m_next = nullptr;
}

void node::setValue(int value)
{
    m_value = value;
}

int node::getValue()
{
    return m_value;
}

void node::setNext(node* prev)
{
    m_next = prev;
}

node* node::getNext()
{
    return m_next;
}
