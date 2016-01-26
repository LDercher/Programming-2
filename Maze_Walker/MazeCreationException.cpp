/**
*	@file : MazeCreationException.cpp
*	@author :  Luke Dercher
*	@date : 2015.03.15
*	Purpose: Implementation of Maze Creation Exception.
*/

#include"mazecreationexception.h"
#include<stdexcept>

mazecreationexception::mazecreationexception(const char* msg): std::runtime_error(msg)
{
}
