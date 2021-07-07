#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
#include "elf.h"
using namespace std;

//Default constructor
elf::elf():creature(3,50,50) //initilizing elf with default parameters strength:50 hitpoints:50
{
//deliberately empty
}
//Constructor with arguments
elf::elf(int newstrength, int newhitpoints):creature(3,newstrength, newhitpoints)
{
}
//implementation of getDamage
int elf::getDamage()
{
   int value = creature::getDamage();
   int m = (rand() % 10 + 1);
   if (m <= 5)
   {
       cout << " Elf inflicts " << value << " additional damage! " << endl;
       value = (value * 2);
   }
   return value;
}