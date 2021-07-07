#include <iostream>
#include <ctime>
#include <cstdlib>
#include "balrog.h"
#include "demon.h"
using namespace std;
//Default constructor
balrog::balrog():demon(2,30,30) //initilizing balrog with default parameters strength:30 hitpoints:30
{
	//deliberately empty
}
balrog::balrog(int newStrength, int newHitpoints):demon(2,newStrength, newHitpoints){//Constructor with arguments
	//deliberately empty
}

int balrog::getDamage(){//implementation of getDamage
   int value = demon::getDamage();
   int randValue = ((rand() % balrog::getStrength()) + 1);
   cout << " Balrog speed attack inflicts " << randValue << " damage! " << endl;
   value = (value + randValue);
   return value;
}

