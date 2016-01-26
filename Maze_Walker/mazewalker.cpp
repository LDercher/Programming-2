#include "mazewalker.h"

mazewalker::mazewalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs): m_startPos(startRow, startCol), m_curPos(startRow, startCol)
{
    m_isDFS = dfs;

    m_rows = rows;

    m_cols = cols;

    m_maze = mazePtr;

    m_visited = new bool*[m_rows];

    for(int i = 0; i < m_cols; i++)
    {
        m_visited[i] = new bool[m_cols];
    }

    for (int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j< m_cols; j++)
        {
            m_visited[i][j]= false;
        }
    }

    for (int i = 0; i < m_rows; i++)
    {

        for(int j = 0; j< m_cols; j++)
        {
            std::cout<< m_visited[i][j];
        }
        std::cout<<"\n";
    }

}

mazewalker::~mazewalker()
{
    for(int i = 0; i < m_rows; i++)
    {
       delete[] m_visited[i];
    }
    delete [] m_visited;
}

void mazewalker::walkMaze()
{
    storeValidMoves();

    if (m_isDFS)
    {
        while(!isGoalReached()&& m_moveStack.size() >  0)
        {
            move(m_moveStack.top());

           m_moveStack.pop();

            storeValidMoves();
        }
    }
    else
    {
        while(!isGoalReached()&& m_moveQueue.size() >  0)
        {

            move(m_moveQueue.front());

            m_moveQueue.pop();

            storeValidMoves();
        }
    }

    if (isGoalReached())
    {
        std::cout<<"Exit found!";
    }
    else
    {
        std::cout<<"No way out!";
    }
}

void mazewalker::storeValidMoves()
{

   position posPis1 (m_curPos.getRow()-1,m_curPos.getCol());
   if (isValidMove(posPis1))
   {

       if (m_isDFS)
       {
           m_moveStack.push(posPis1);
       }
       else
       {
           m_moveQueue.push(posPis1);
       }
   }

   position posPis2 (m_curPos.getRow(),m_curPos.getCol()+1);

   if (isValidMove(posPis2))
   {
       if (m_isDFS)
       {
            m_moveStack.push(posPis2);
       }
       else
       {
            m_moveQueue.push(posPis2);
       }
   }


   position posPis3(m_curPos.getRow() + 1,m_curPos.getCol());

   if (isValidMove(posPis3))
   {
        if (m_isDFS)
        {
             m_moveStack.push(posPis3);
        }
        else
        {
             m_moveQueue.push(posPis3);
        }
   }


   position posPis4(m_curPos.getRow(),m_curPos.getCol()-1);

    if (isValidMove(posPis4))
    {
         if (m_isDFS)
         {
             m_moveStack.push(posPis4);
         }
         else
         {
             m_moveQueue.push(posPis4);
         }
    }

}


bool mazewalker::isValidMove(position &p)
{
    if (p.getCol() >= m_cols || p.getCol() < 0)
    {
        return false;
    }
    if (p.getRow() >= m_rows || p.getRow() < 0 )
    {
        return false;
    }
    if (m_visited[p.getRow()][p.getCol()])
    {
        return false;
    }
    if (m_maze[p.getRow()][p.getCol()] == 'W')
    {
        return false;
    }
    return true;

}

void mazewalker::move(position& p)
{

    m_curPos.setRow(p.getRow());
    m_curPos.setCol(p.getCol());


    for (int i=0; i<m_rows; i++)
    {
        for(int j=0; j<m_cols; j++)
        {
            std::cout << m_visited[i][j];
        }
        std::cout <<"\n";
    }

    m_visited[p.getRow()][p.getCol()] = true;

    std::cout << "Visiting position: " << m_curPos.getRow() << ", " << m_curPos.getCol()<<"\n";

}



bool mazewalker::isGoalReached() const
{
    if (m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
    {
           return true;
    }
    else
    {
        return false;
    }

}
