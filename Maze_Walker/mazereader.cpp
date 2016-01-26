#include "mazereader.h"




MazeReader::MazeReader(std::string file) throw (mazecreationexception)
{
    mazeIn.open(file);

    if (!mazeIn.is_open())
    {
        throw (mazecreationexception("unable to open file...."));
    }
    else
    {
        mazeIn >> m_rows;

        mazeIn >> m_columns;

        maze = new char*[m_rows];

        for(int i = 0; i < m_columns; i++)
        {
            maze[i] = new char[m_columns];
        }


        if(m_rows < 0 && m_columns < 0)
        {
            throw (mazecreationexception("Invalid input for maze size...."));
        }
        else
        {

            mazeIn >> startRow;

            mazeIn >> startCol;

            if (startRow < 0 || startRow > m_rows || startCol <  0 || startCol > m_columns)
            {
                throw (mazecreationexception("Starting position outside of maze...."));
            }
        }
    }

    readMaze();
}

MazeReader::~MazeReader()
{
    for(int i = 0; i < m_rows; i++)
    {
       delete[] maze[i];
    }
    delete [] maze;
}

char** MazeReader::getMaze() const
{
    return maze;
}

int MazeReader::getCols() const
{
    return m_columns;
}

int MazeReader::getRows() const
{
    return m_rows;
}

int MazeReader::getStartCol() const
{
    return startCol;
}

int MazeReader::getStartRow() const
{
    return startRow;
}

void MazeReader::readMaze() throw (mazecreationexception)
{
    for (int i=0; i < m_rows; i++)
    {
        for (int j= 0; j < m_columns; j++)
        {
            mazeIn >> maze[i][j];
        }
    }
}
