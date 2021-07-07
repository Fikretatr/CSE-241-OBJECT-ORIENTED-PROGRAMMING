#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
using namespace std;
class creature
{
   public:
   creature();// initialize to human, 10 strength, 10 hitpoints
   creature(int newStrength, int newHitpoints);
   creature(int newType, int newStrength, int newHitpoints);
   int getDamage();// Returns amount of damage this creature- inflicts in one round of combat
   string getSpecies();
   int getHitpoints();//accessors function
   int getStrength();//accessors function
   void setHitpoints(int newHitpoints);//mutators function
   void setStrength(int newStrength);//mutators function
   
   private:
   int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
   int strength; // how much damage this creature inflicts
   int hitpoints; // how much damage this creature can sustain
   

};

#endif