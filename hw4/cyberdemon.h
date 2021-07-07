#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"
#include <iostream>
#include <string>
class cyberdemon : public demon
{
public:
   cyberdemon();
   cyberdemon(int newStrength, int newHitpoints);

};
#endif