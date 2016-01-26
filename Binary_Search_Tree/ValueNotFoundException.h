/**
*	@file : ValueNotFoundException.h
*	@author: Luke Dercher
*	@date: 2015.04.11
*	@purpose: Exception class used to tell when a value is not found in the binary search tree
*/

#ifndef VALUENOTFOUNDEXCEPTION_H
#define VALUENOTFOUNDEXCEPTION_H

#include<stdexcept>

class ValueNotFoundException: public std::runtime_error
{
public:
    ValueNotFoundException(const char* msg);
};

#endif // VALUENOTFOUNDEXCEPTION_H
