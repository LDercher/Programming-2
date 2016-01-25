/**
*	@file : main.cpp
*	@author :  Luke Dercher
*	@date : 2015.02.15
*	Purpose: Used to create a double linked list filled with nodes.
*/


#include "node.h"
#include "doublell.h"
#include <iostream>
#include <stdexcept>

void printMenu()
{
    std::cout << 	"\n\nMake choice\n"
        <<	"1) push value onto front\n"
        <<	"2) push value onto back\n"
        <<	"3) insert behind a value\n"
        <<	"4) insert ahead of a value\n"
        <<	"5) remove value\n"
        <<  "6) remove duplicate values\n"
        <<	"7) print list\n"
        <<	"8) Quit\n"
        << 	"Your choice: ";
}

int main ()
{

    int choice=0;

    DoubleLL<int> intList;

    printMenu();

    std::cin >> choice;


    while (choice != 8)
       {
        std::cout<< choice << "\n";
            switch (choice)
            {
                case 1 :
                    int value;

                    std::cout << "Give a value. \n\n";

                    std::cin >> value;

                    std::cout << value << " added to the front of the list. \n";

                    intList.pushFront(value);

                    break;

                case 2 :

                    int value2;

                    std::cout << "Give a value. \n\n";

                    std::cin >> value2;

                    std::cout << value2 << " added to the back of the list. \n";

                    intList.pushBack(value2);

                    break;
                case 3:

                   try
                    {


                        std::cout<< "Give a value to insert. \n";

                        int inVal1;

                        std::cin>>inVal1;

                        std::cout<<"Give a value to insert behind. \n\n";

                        int behind;

                        std::cin>>behind;

                        std::cout<<"Attempting to insert "<<inVal1 << " behind "<< behind<< "\n\n";

                        intList.insertBehind(behind,inVal1);

                        std::cout<< inVal1 << " inserted behind "<< behind;
                    }
                     catch(std::runtime_error& e)
                    {
                         std::cout<<e.what()<<"\n\n";
                    }

                    break;


                case 4:

                    try
                    {

                        std::cout<< "Give a value to insert. \n";

                        int inVal;

                        std::cin>>inVal;

                        std::cout<<"Give a value to insert ahead of.\n\n";

                        int aheadOf;

                        std::cin>>aheadOf;

                        std::cout<<"Attempting to insert "<<inVal << " ahead of "<< aheadOf<<"\n\n";


                        intList.insertAhead(aheadOf,inVal);

                        std::cout<< inVal << " inserted ahead of "<< aheadOf;

                    }
                    catch(std::runtime_error& e)
                    {
                        std::cout<<e.what()<<"\n\n";
                    }

                    break;

                case 5:

                        int remVal;

                        std::cout<<"Give a value to remove. \n";

                        std::cin>>remVal;

                        std::cout<<"You gave "<<remVal<<"\n\n";

                        if (intList.remove(remVal))
                        {
                            std::cout<<remVal<<" removed from the list. \n";
                        }
                        else
                        {
                            std::cout<<remVal<<" could not be removed from the list. \n";
                        }


                break;

                case 6:

                    std::cout<<"Removing all duplicate values from the list \n";

                    intList.removeDups();

                    break;

                case 7:

                    intList.printList();

               break;
            }

            printMenu();
            std::cin >> choice;

            if (choice == 8)
            {
                std::cout<<"8 \n\n";
            }
       }



    std::cout<<"Program ending...";

    return 0;
}
