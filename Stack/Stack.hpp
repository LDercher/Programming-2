/**
*	@file : Stack.hpp
*	@author: Luke Dercher
*	@date: 2015.03.27
*	@purpose: Implementation of stack class.
*/



template <typename T>
Stack<T>::Stack()
{

	m_top = nullptr;

	m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{

	while (m_size!=0)
	{
        pop();
	}
}

template <typename T>
bool Stack<T>::isEmpty() const
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

template <typename T>#include<stdexcept>
#include"PreconditionViolationException.h"
#include"node.h"
void Stack<T>::push (const T newEntry)
{
	if (m_size == 0)
    	{
            m_top = new node<T>;

        	m_top -> setValue(newEntry);

            m_top -> setNext (nullptr);
    	}
    	else
    	{
            node<T>* temp = new node<T>;

        	temp -> setValue(newEntry);

            temp ->setNext(m_top);

            m_top =temp;
    	}

    	m_size ++;
} 

template <typename T>
T Stack<T>::pop () throw(PreconditionViolationException)
{
	if (m_size == 1)
    {
        T value =  m_top->getValue();
	 
		delete m_top;

        m_top = nullptr;

        m_size--;
		
		return value;

    }
    else if (m_size > 1)
   	{
		T value =  m_top->getValue();        	
		
        node<T>* temp = m_top;

        m_top = m_top -> getNext();

        delete temp;

        m_size --;

		return value;

    }
   	 else
    {
        throw(PreconditionViolationException("Pop attempted on an empty stack"));
    }
}

template <typename T>
T Stack<T>::peek () const throw(PreconditionViolationException)
{

	if (m_size >= 1)
	{
		return m_top->getValue();
	}
	else
	{
        throw(PreconditionViolationException("Peek attempted on an empty stack"));
	}
}

template <typename T>
int Stack<T>::size() const
{
	return m_size;
}

template <typename T>
void Stack<T>::print () const
{
	if (m_size == 0)
    	{
        	std::cout << "Stack empty";
    	}
    	else
    	{
            node<T>* temp = m_top;


            while (temp  != nullptr)
             {

            	std::cout << temp->getValue();

            	if(temp->getNext() != nullptr)
            	{
                	std::cout<<",";
            	}

            	temp = temp ->getNext();
            }
        }
}

template <typename T>
bool Stack<T>::operator < (const StackInterface<T>& rhs) const
{
    if (this->m_size < rhs.size())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template <typename T>
bool Stack<T>::operator <= (const StackInterface<T>& rhs) const
{

    if (this->m_size <= rhs.size())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template <typename T>
bool Stack<T>::operator > (const StackInterface<T>& rhs) const
{
    if (this->m_size > rhs.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Stack<T>::operator >= (const StackInterface<T>& rhs) const
{

    if (this->m_size >= rhs.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Stack<T>::operator == (const StackInterface<T>& rhs) const
{

    if (this->m_size == rhs.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Stack<T>::operator != (const StackInterface<T>& rhs) const
{

    if (this->m_size != rhs.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
