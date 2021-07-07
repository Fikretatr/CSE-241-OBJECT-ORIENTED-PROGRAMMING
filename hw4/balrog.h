#ifndef BALROG_H
#define BALROG_H
#include "demon.h"
#include <iostream>
using namespace std;
class balrog : public demon
{
public:
   balrog();
   balrog(int newStrength, int newHitpoints);
   int getDamage();
};
#endif