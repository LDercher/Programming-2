/** 
 *	@file : main.cpp 
 *	@author :  Luke Dercher
 *	@date : 04 - 19 - 2015 
 *	Purpose: The main class instantiates the MazeReader and MazeWalker classes, and does basic filtering of user input. 
 *			The primary job of this class is to create and manage the maze classes. 
 */ 

#include "mazereader.h"
#include "mazewalker.h"
#include "mazecreationexception.h"
#include <string>

int main(int argc, char** argv)
{
    bool dfs = false;

    if(argc == 3)
    {
        std::string search = argv[2];

        if (search == "-dfs" || search == "-bfs")
        {

            try
            {
                std::string file = argv[1];

                MazeReader* MR = new MazeReader(file);

                if(search == "-dfs")
                {
                    dfs = true;
                }

                mazewalker* MW = new mazewalker(MR->getMaze(), MR->getStartRow(), MR->getStartCol(), MR->getRows(), MR->getCols(), dfs );

                MW->walkMaze();

                delete MR;

                delete MW;
            }
            catch(std::runtime_error& e)
            {
                std::cout<<"Exception: " << e.what()<<"\n\n";
            }



        }
    }


    return 0;
}
