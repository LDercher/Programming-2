    /**
*	@file : main.cpp
*	@author: Luke Dercher
*	@date: 2015.04.11
*	@purpose: main used to create a binary search tree and copies
*/

#include "binarysearchtree.h"
#include "BSTI.h"
#include "node.h"
#include "valuenotfoundexception.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include<stdexcept>


void printMenu()
{
    std::cout << 	"\n\nInput a selection:\n"
        <<	"1) Add more values to original tree \n"
        <<	"2) Copy the original tree\n"
        <<	"3) Delete the original tree (one time only)\n"
        <<	"4) Print original tree\n"
        <<	"5) Print copy\n"
        <<	"6) Search original tree\n"
        <<  "7) Search copy\n"
        <<	"8) Exit\n"
        << 	"Your choice: ";
}


int main (int argc, char** argv)
{
    bool added;

    int choice, numNodes, add, orderChoice, search;

    BSTI<int>* BSTCopy =nullptr;

    if (argc > 1)
    {
        numNodes = std::stoi(argv[1]);

        std::cout<<"Arg Count: "<< argc << "\n";

        std::cout<<"Node count: "<< numNodes << "\n\n";

        BSTI<int>* BST = new BinarySearchTree<int>();

        std::default_random_engine generator(time(nullptr));
        std::uniform_int_distribution<int> distribution(-800000,800000);

        std::cout<< "Filling original tree with " << numNodes << " values. \n";

        while (numNodes > 0)
        {
            numNodes--;

            added = distribution(generator);

            std::cout<<"Adding "<< added << "to original tree \n";

            BST->add(added);
        }

        while (choice!= 8)
        {
            printMenu();

            std::cin>>choice;

            std::cout<<"You chose: "<<choice<< "\n";

            switch (choice)
            {
                case 1:

                    if (BST == nullptr)
                    {
                        std::cout<<"I pity the fool that tries to add to a tree that doesn't exist";
                    }
                    else
                    {
                        std::cout<<"Input a value to add to the original tree:";

                        std::cin>>add;

                        bool added = BST->add(add);

                        if (added)
                        {
                            std::cout<<"Adding " << add << " to the original tree";
                        }
                        else
                        {
                            std::cout<<add<<" could not be added to the tree.";
                        }

                    }

                    break;

                case 2:

                    if (BST == nullptr)
                    {
                        std::cout<<"I pity the fool that tries to copy to a tree that doesn't exist";
                    }
                    else
                    {
                        std::cout<<"Copying the orginal tree....";

                        BSTCopy = BST->clone();
                    }

                    break;

                case 3:

                    if (BST == nullptr)
                    {
                        std::cout<<"I pity the fool that tries to delete a tree that doesn't exist";
                    }
                    else
                    {

                        std::cout<<"Deleting the orginal tree....";

                        delete BST;

                        BST = nullptr;

                    }

                    break;

                 case 4:

                    if (BST == nullptr)
                    {
                        std::cout<<"I pity the fool that tries to print a tree that doesn't exist";
                    }
                    else
                    {
                        std::cout<<"print order options: \n"
                                 <<"        0 - pre-order \n"
                                 <<"        1 - in-order  \n"
                                 <<"        2 - post-order \n"
                                 <<"Choice:        ";

                        std::cin>>orderChoice;

                        std::cout<<"Your chose: "<< orderChoice << "\n";

                        if(orderChoice == 0)
                        {
                            BST->printTree(PRE_ORDER);
                        }
                        else if (orderChoice == 1)
                        {
                            BST->printTree(IN_ORDER);
                        }
                        else if (orderChoice == 2)
                        {
                            BST->printTree(POST_ORDER);
                        }
                     }

                    break;

                  case 5:

                    if (BSTCopy == nullptr)
                    {
                        std::cout<<"I pity the fool that tries to print a tree that doesn't exist";
                    }
                    else
                    {
                        std::cout<<"print order options: \n"
                                 <<"        0 - pre-order \n"
                                 <<"        1 - in-order  \n"
                                 <<"        2 - post-order \n"
                                 <<"Choice:        ";

                        std::cin>>orderChoice;

                        std::cout<<"Your chose: "<< orderChoice << "\n";

                        if(orderChoice == 0)
                        {
                            BSTCopy->printTree(PRE_ORDER);
                        }
                        else if (orderChoice == 1)
                        {
                            BSTCopy->printTree(IN_ORDER);
                        }
                        else if (orderChoice == 2)
                        {
                            BSTCopy->printTree(POST_ORDER);
                        }
                    }

                    break;

                case 6:

                    if(BST==nullptr)
                    {
                        std::cout<<"I pity the fool that tries to search in a tree that doesn't exist";
                    }
                    else
                    {
                        std::cout<<"Input a value to search for\n";

                        std::cin>>search;

                        std::cout<<"Searching for "<< search <<"....\n";

                        try
                        {
                           int searchVal =  BST->search(search);

                           std::cout<<searchVal<<" is in the tree.";
                        }
                        catch(std::runtime_error& e)
                       {
                            std::cout<<"Exception: " << e.what()<<"\n\n";
                       }


                    }

                    break;

                 case 7:

                    if (BSTCopy == nullptr)
                    {
                        std::cout<<"I pity the fool that tries to search in a tree that doesn't exist";
                    }
                    else
                    {
                        std::cout<<"Input a value to search for\n";

                        std::cin>>search;

                        std::cout<<"Searching for "<< search <<"....\n";

                        if (BSTCopy->search(search))
                        {
                            std::cout<<search<< " is in the tree";
                        }
                        else
                        {
                            std::cout<<search<< " is not in the tree";
                        }
                    }

                    break;

            case 8:

                    if (BST == nullptr)
                    {
                         std::cout<<"I pity the fool that tries to add a tree that doesn't exist";
                    }
                    else
                    {
                         int tote = BST->addAll();

                         std::cout<<tote<<"\n";
                    }

                    break;

            }
        }

        if (BST != nullptr)
        {
            delete BST;
        }

        if (BSTCopy != nullptr)
        {
            delete BSTCopy;
        }


    }
    std::cout << "Exiting...";


    return 0;
}
