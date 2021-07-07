#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
#include "human.h"
using namespace std;

human::human():creature()//Default constructor
{
	//deliberately empty
}
//Constructor with arguments
human::human(int newStrength, int newHitpoints):creature(0,newStrength, newHitpoints)
{
	//deliberately empty
}
