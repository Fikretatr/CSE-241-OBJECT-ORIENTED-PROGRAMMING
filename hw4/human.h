#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "creature.h"
using namespace std;
class human : public creature
{
public:
   human();
   human(int newStrength, int newHitpoints);

private:
  int type = 0;
};
#endif