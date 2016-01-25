/**
*	@file : PreconditionViolationException.cpp
*	@author :  Luke Dercher
*	@date : 2015.03.15
*	Purpose: Implementation of Precondition Violation Exception.
*/

#include"PreconditionViolationException.h"
#include<stdexcept>

PreconditionViolationException::PreconditionViolationException(const char* msg): std::runtime_error(msg)
{
}
