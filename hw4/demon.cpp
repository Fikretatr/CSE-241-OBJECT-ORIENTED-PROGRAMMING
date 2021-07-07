#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
#include "demon.h"
using namespace std;
//Default constructor
demon::demon(int newType,int newStrength, int newHitpoints):creature(newType,newStrength, newHitpoints)
{
	//deliberately empty
}

//implementation of getDamage
int demon::getDamage(){
   int value = creature::getDamage();
   if ((rand() % 100) < 5)
   {
       cout << "Demons inflicts 50 additional damage points ! " << endl;
       value = (value + 50);
   }
   return value;
}