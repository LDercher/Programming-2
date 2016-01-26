/**
*	@file : ValueNotFoundException.cpp
*	@author: Luke Dercher
*	@date: 2015.04.11
*	@purpose: Implementation of valuenotfoundexception class
*/

#include "valuenotfoundexception.h"

ValueNotFoundException::ValueNotFoundException(const char* msg): std::runtime_error(msg)
{
}
