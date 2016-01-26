#include "position.h"

position::position(int row, int col)
{
    m_row = row;

    m_col = col;
}

int position::getCol() const
{
    return m_col;
}

int position::getRow() const
{
    return m_row;
}

void position::setRow(int value){

    m_row = value;

}

void position::setCol(int value){

    m_col = value;

}
