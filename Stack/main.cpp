/**
*	@file : main.cpp
*	@author :  Luke Dercher
*	@date : 2015.03.15
*	Purpose: Main used to imlement the stack class.
*/

#include "Stack.h"
#include "StackInterface.h"
#include "node.h"
#include "PreconditionViolationException.h"
#include <iostream>
#include<string>


void printMenu()
{
    std::cout << 	"\n\nSelect an action:\n"
        <<	"1) Add something to stack 1\n"
        <<	"2) Add something to stack 2\n"
        <<	"3) See what is at the top of stack 1\n"
        <<	"4) See what is at the top of stack 2\n"
        <<	"5) Print contents in stack 1\n"
        <<	"6) Print contents in stack 2\n"
         << "7) Pop stack 1 \n"
        <<	"8) Pop stack 2\n"
        <<  "9) Compare Stacks \n"
        <<  "10) Quit \n"
        << 	"Your choice: ";
}

template <typename T>
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2)
{
	std::cout 	<< "\nComparison of stacks:\n"
			<< "lane 1 < lane 2: " <<  (s1 <  s2) 	<< "\n"
			<< "lane 1 > lane 2: " <<  (s1 >  s2) 	<< "\n"
			<< "lane 1 >= lane 2: " << (s1 >= s2) 	<< "\n"
			<< "lane 1 <= lane 2: " << (s1 <= s2) 	<< "\n"
			<< "lane 1 == lane 2: " << (s1 == s2) 	<< "\n"
			<< "lane 1 != lane 2: " << (s1 != s2) 	<< "\n";
}


int main ()
{
    int choice = 0;

    std::string T_stack1;

     std::string T_stack2;

    StackInterface<std::string>* lane1 = new Stack<std::string>();

	StackInterface<std::string>* lane2 = new Stack<std::string>();

	while (choice != 10)
       {
        std::cout<< choice << "\n";
            switch (choice)
            {
                case 1:

                    std::cout << "What is going on stack 1?: \n";

                    std::cin >> T_stack1;

                    std::cout << T_stack1 << " successfully added to Stack 1 \n";

                    lane1->push(T_stack1);

                    break;

                case 2:

                    std::cout << "What is going on stack 2?: \n";

                    std::cin >> T_stack2;

                    std::cout << T_stack2 << " successfully added to Stack 2 \n";

                    lane2->push(T_stack2);

                    break;
                case 3:

                   try
                    {
			
                        std::string peek1 = lane1->peek();
			
                        std::cout<<peek1<< "Is on the top of the stack";
                    }
                     catch(std::runtime_error& e)
                    {
                         std::cout<<"Exception: " << e.what()<<"\n\n";
                    }

                    break;


                case 4:

                    try
                    {
                        std::string peek2 = lane2->peek();
			
                        std::cout<<peek2<< "Is on the top of the stack";
                    }
                     catch(std::runtime_error& e)
                    {
                         std::cout<<"Exception: " <<e.what()<<"\n\n";
                    }

                    break;

                case 5:

                     lane1->print();

                break;
                

                case 6:

                     lane2->print();
		
                break;

                case 7:

                    try
                    {

                        std::cout<< lane1->pop() <<" removed from stack 1 \n";

                    }
                    catch(std::runtime_error& e)
                    {
                        std::cout<<"Exception: " << e.what()<<"\n\n";
                    }

                break;

                case 8:

                    try
                    {


                        std::cout<< lane2->pop() <<" removed from stack 2 \n";

                    }
                    catch(std::runtime_error& e)
                    {
                        std::cout<<"Exception: " << e.what()<<"\n\n";
                    }

                break;

                case 9:

                    compareStacks((*lane1), (*lane2));

                break;

            }

            printMenu();
            std::cin >> choice;
       }
    std::cout<< choice << "\n";
    std::cout<< "Program ending";

delete lane1;

delete lane2;

return 0;
}
