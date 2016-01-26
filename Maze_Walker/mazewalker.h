/** 
 *	@file : mazewalker.h
 *	@author :  Luke Dercher
 *	@date : 04 - 19 - 2015 
 *	Purpose: This class navigates the maze using a stack/queue, an array of boolean values representing visited positions, 
 *		and an array of chars representing the maze read with the MazeReader class.   
 */ 


#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include "position.h"
#include <iostream>
#include <stack>
#include <queue>


class mazewalker
{
public:
     /**
    *	@pre The mazePtr pointer is to a valid maze.
    *	@post A maze walker if created with all needed flags set and the visited array contains all false.
    */
    mazewalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);

     /**
    *	@pre The maze is a valid maze.
    *	@post The maze is traversed until (either dfs or bfs) the end is reached or all moves are exhausted. The visited array printed during the traversal.
    */
     void walkMaze();



     /**
    *	@post Deletes bool array m_visited
    */
     ~mazewalker();


protected:

     /**
    *	@pre The current position is valid.
    *	@post Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current position.
    */
    void storeValidMoves();


    /**
   *	@pre A position to be checked is passed in
   *	@return True if the move is valid
   */
    bool isValidMove(position& p);


    /**
    *	@pre The position is valid.
    *	@post The current position is set to p and the position is updated as marked.
    */
    void move(position& p);


    /**
    *	@returns If the current position is the exit, true is returned. False is returned otherwise.
    */
    bool isGoalReached() const;

        //member variables


    bool m_isDFS;
    char** m_maze;
    bool** m_visited;
    int m_rows, m_cols;
    position m_startPos;
    position m_curPos;

    std::stack<position> m_moveStack;
    std::queue<position> m_moveQueue;
};

#endif // MAZEWALKER_H
