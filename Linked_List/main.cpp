/**
*	@file : main.cpp
*	@author :  Luke Dercher
*	@date : 2015.02.05
*	Purpose: Main used for creating a linkedlist and prompting the user to add and remove nodes in the list.
*/


#include "node.h"
#include "linkedlist.h"
#include <iostream>


void printMenu()
{
    std::cout << "\n\nSelect from the following menu:\n"
            << "1) Add to the front of the list\n"
            << "2) Add to the end of the list\n"
            << "3) Remove from front of the list\n"
            << "4) Remove from back of the list\n"
            << "5) Print the list\n"
            << "6) Search for value\n"
            << "7) remove value from index\n"
            << "8) Exit\n"
            << "Enter your choice: ";
}


int main ()
{
    int choice=0;

    linkedlist L1 = linkedlist();

    printMenu();

    std::cin >> choice;

    while (choice != 8)
       {
        std::cout<<"You chose "<< choice << "\n";
            switch (choice)
            {
                case 1 :
                    int value;

                    std::cout << "Enter your value to add to the list \n";

                    std::cin >> value;

                    std::cout << "Adding " << value << " to the list";

                    L1.addFront(value);

                    break;

                case 2 :

                    int value2;

                    std::cout << "Enter your value to add to the list \n";

                    std::cin >> value2;

                    std::cout << "Adding " << value2 << " to the list";

                    L1.addBack(value2);

                    break;
                case 3:

                    std::cout<< "Attempting Removal from the list \n";


                        if (L1.removeFront())
                        {
                           std::cout<< "Removal successful \n\n";
                        }
                        else
                        {
                           std::cout<< "Removal unsuccessful. List empty";
                        }

                    break;
                case 4:

                    std::cout<< "Attempting Removal from the list \n";


                        if (L1.removeBack())
                        {
                            std::cout<< "Removal successful \n\n";
                        }
                        else
                        {
                            std::cout<< "Removal unsuccessful. List empty";
                        }

                    break;
                case 5:

                    std::cout<<"Printing list \n";

                    L1.printList();

                    break;
                case 6:

                    int search;

                    std::cout << "Enter a value to search for \n";

                    std::cin >> search;

                    std::cout << "Searching for " << search << "\n";

                    if (L1.search(search))
                    {
                        std::cout << search << " is in the list \n";

                    }
                    else
                    {
                        std::cout << search << " is not in the list \n";
                    }

                    break;

                case 7:

                    int index;

                    std::cout << "from what index to do want to remove the value?\n";

                    std::cin >> index;

                    if (L1.deleteIndex(index))
                    {
                        std::cout << "value at index " << index << "successfully removed\n";
                    }
                    else
                    {
                        std::cout << "unable to remove value at index " << index << "\n";
                    }

                    break;




            }

            printMenu();
            std::cin >> choice;
       }

    return 0;
}
