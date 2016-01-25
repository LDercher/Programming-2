/**
*	@file : PreconditionViolationException.h
*	@author :  Luke Dercher
*	@date : 2015.03.15
*	Purpose: New exception, derived from the runtime_error class.
*/

#ifndef PRECONDITION_VIOLATION_EXCEPTION
#define PRECONDITION_VIOLATION_EXCEPTION

#include<stdexcept>

class PreconditionViolationException: public std::runtime_error
{
public:
	PreconditionViolationException(const char* msq);
};
#endif //PRECONDITION_VIOLATION_EXCEPTION
