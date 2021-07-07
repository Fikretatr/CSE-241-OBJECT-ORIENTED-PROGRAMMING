#include <iostream>
#include <cstdlib>
#include <ctime>
#include "creature.h"
using namespace std;

creature::creature(){//Default constructor
   hitpoints = 10;
   strength = 10;
   type = 0;
   srand(time(0));
}

creature::creature(int newStrength, int newHitpoints){//Constructor with two arguments
   hitpoints = newHitpoints;
   strength = newStrength;
   srand(time(0));
}
creature::creature(int newType, int newStrength, int newHitpoints){//Constructor with three arguments
   type = newType;
   hitpoints = newHitpoints;
   strength = newStrength;
   srand(time(0));
}
void creature::setStrength(int newStrength){// implementation of setStrength
   strength = newStrength;
}
int creature::getStrength(){// implementation of getStrength
   return strength;
}
void creature::setHitpoints(int newHitpoints){// implementation of setHitpoints
   hitpoints = newHitpoints;
}
int creature::getHitpoints(){// implementation of getHitpoints
   return hitpoints;
}
int creature::getDamage(){// implementation of getDamage
   int value;
   value = ((rand() % strength) + 1);
   cout << "The " << getSpecies() << " attacks for " << value << " points!" << endl;
   return value;
}
//Here is an implementation of the getSpecies( )
string creature::getSpecies()
{
   switch (type)
   {
   case 0: return "Human";
   case 1: return "Cyberdemon";
   case 2: return "Balrog";
   case 3: return "Elf";
   }
   return "Unknown";
}