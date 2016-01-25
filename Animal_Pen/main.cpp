/**
*	@file : main.cpp
*	@author: Luke Dercher
*	@date: 2015.02.27
*	@purpose: Main, used to create the farmanimal stack and add animals to the stack, and then delete the stack afterwards.
*/

#include "stack.h"
#include "animalpen.h"
#include "node.h"
#include "FarmAnimal.h"
#include "cow.h"
#include "chicken.h"
#include "cyberchicken.h"
#include "PreconditionViolationException.h"
#include <iostream>
#include<string>



void goodbyMessage(const FarmAnimal& animal)
{
    std::cout<<"Upon release the "<< animal.getName() << " said " << animal.getSound() <<"\n";
}

void printMenu()
{
    std::cout << 	"\n\nSelect an animal to add to the pen:\n"
        <<	"1) Cow (produces milk)\n"
        <<	"2) Chicken (cannot lay eggs)\n"
        <<	"3) Cyber Chicken (seems dangerous, but lays eggs)\n"
        <<	"-------------------------------------------------\n"
        << 	"choice: ";
}

int main ()
{

    bool done = false;

    int eggs = 0;

    double milk = 0.0;

    AnimalPen AP;

    int choice;

    double gallons;

    int eggNum;

    while (!done)
    {
          printMenu();

          std::cin>>choice;

          if (choice ==1)
          {
             Cow* moo = new Cow();

             AP.addAnimal(moo);

             std::cout<<"How many gallons of milk did this cow produce?:";

             std::cin>>gallons;

             milk = milk + gallons;

             moo ->  setMilkProduced(gallons);

          }
          else if (choice == 2)
          {
              Chicken* bock = new Chicken();

              AP.addAnimal(bock);

              std::cout<<"Add an eggless chicken to the pen? OK. You're the boss.";

          }
          else if (choice == 3)
          {

              CyberChicken* destroy = new CyberChicken();

              AP.addAnimal(destroy);

              std::cout<<"How many eggs did this cyber chicken produce?";

              std::cin>>eggNum;

              eggs = eggs + eggNum;

              destroy->setCyberEggs(eggNum);
          }

          std::cout<<"Done adding animals? (y/n)/n";

          char yesOrNo;

          std::cin>>yesOrNo;

          if(yesOrNo == 'y')
          {
              done = true;
          }
          else
          {
              done = false;
          }

    }

std::cout<<"Releasing all the animals!\n";

std::cout<<"-----------------------------\n\n";

FarmAnimal* top;

while (!AP.isPenEmpty())
    {
       top = AP.peekAtNextAnimal();

       if (top->getName() == "Cow")
       {

           std::cout<<"This cow produced "<<static_cast<Cow*>(top)->getMilkProduced() << " gallons of milk\n";

           goodbyMessage(*top);

           std::cout<< top->getName() << " destructor called\n";

           AP.releaseAnimal();

           delete top;
       }
       else if (top->getName() == "Chicken")
       {
           std::cout<<"Chicken unable to lay eggs. Perhaps cybornetic implants will help?\n";

           goodbyMessage(*top);

           std::cout<< top->getName() << " destructor called\n";

           AP.releaseAnimal();

           delete top;
       }
       else if (top->getName() == "Cyber Chicken")
       {

           std::cout<<"This chicken laid "<<static_cast<CyberChicken*>(top)->getCyberEggs() << " cyber eggs. Humanity is in trouble. \n";

           goodbyMessage(*top);

           std::cout<< top->getName() << " destructor called\n";

           AP.releaseAnimal();

           delete top;
       }
    }


    std::cout<<"Your farm produced "<< milk <<" gallons of milk and "<< eggs << " eggs.";


    return 0;
}
