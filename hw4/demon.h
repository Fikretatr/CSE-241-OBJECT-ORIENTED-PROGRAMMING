#ifndef DEMON_H
#define DEMON_H
#include "creature.h"
#include <iostream>
using namespace std;
class demon : public creature
{
public:
   demon(int newType, int newStrength, int newHitpoints);
   int getDamage();
};
#endif