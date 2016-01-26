/** 
 *	@file : MazeWalker.h 
 *	@author :  Luke Derhcer
 *	@date : 04 - 19 - 2015 
 *	Purpose: This class navigates the maze using a stack/queue, an array of boolean values representing visited positions, 
 *		and an array of chars representing the maze read with the MazeReader class.   
 */ 


#ifndef MAZEREADER_H
#define MAZEREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include "mazecreationexception.h"

class MazeReader
{

public:


   /**
   *   @post A MazeReader is created. A 2D char array is allocated with the maze information.
   *   @throws MazeCreationExecption if any of the following is true:
   *        -The file could not be opened
   *        -The rows or cols are zero or less
   *        -The start position listed is outside the ranges described by the rows and columns
   *        -You do NOT have to check each character for validity, only the rows, cols, and starting position.
   *
   */
   MazeReader(std::string file) throw (mazecreationexception);


   /**
   *   @post The maze is deallocated.
   */
   ~MazeReader();

   /**
   *   @pre the file was formatting and read in correctly
   *   @return Returns pointer to the maze
   */
   char** getMaze() const;


    /**
    *   @pre the file was formatted and read in correctly
    *   @returns the number of columns listed in the file
    */
    int getCols() const;

    /**
    *	@pre the file was formatted and read in correctly
    *	@returns the number of rows listed in the file
    */
    int getRows() const;

     /**
     *	@pre the file was formatted and read in correctly
     *	@returns the starting column
     */
     int getStartCol() const;

     /**
     *	@pre the file was formatted and read in correctly
     *	@returns the starting row
     */
     int getStartRow() const;

protected:

      /**
      *	@pre the file is properly formatted
      *	@post the characters representing the maze are stored
      */
      void readMaze() throw (mazecreationexception);

      std::ifstream mazeIn;

      std::string file;

      int m_rows, m_columns, startRow, startCol;

      char** maze;


};

#endif // MAZEREADER_H
