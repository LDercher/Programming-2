/** 
 *	@file : Position.h 
 *	@author :  Luke Dercher
 *	@date : 04 - 19 - 2015 
 *	Purpose: This class emulates a tuple representing the position in a two-dimensional grid. It is used with the 
 *		MazeWalker class as an ordered pair.  
 */ 


#ifndef POSITION_H
#define POSITION_H

class position
{
public:
    /**
    *	@post Position created with row and col values set.
    */
    position(int row, int col);


     /**
     *	@return row value
     */
     int getRow() const;

     /**
     *	@return col value
     */
     int getCol() const;
     void setRow(int value);
     void setCol(int value);

     private:
     int m_row;
     int m_col;
};

#endif // POSITION_H
