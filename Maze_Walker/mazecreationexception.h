/**
*	@file : mazecreationexception.h
*	@author :  Luke Dercher
*	@date : 2015.03.15
*	Purpose: New exception, derived from the runtime_error class.
*/

#ifndef     MAZE_CREATION_EXCEPTION
#define MAZE_CREATION_EXCEPTION

#include<stdexcept>

class mazecreationexception: public std::runtime_error
{
public:
    mazecreationexception(const char* msq);
};
#endif //MAZE_CREATION_EXCEPTION
