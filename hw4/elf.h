#ifndef ELF_H
#define ELF_H
#include "creature.h"
#include <iostream>
using namespace std;

class elf : public creature
{
public:
   elf();
   elf(int newStrength, int newHitpoints);
   int getDamage();
private:
   int type = 3;
};
#endif