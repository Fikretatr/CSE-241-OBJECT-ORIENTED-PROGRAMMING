#include <iostream>
#include <ctime>
#include <cstdlib>
#include "cyberdemon.h"
#include "demon.h"
using namespace std;

cyberdemon::cyberdemon():demon(1,20,20){//initializing cyberdemon with default parameters strength:20 hitpoints:20
}
cyberdemon::cyberdemon(int newStrength, int newhitpoints):demon(1,newStrength, newhitpoints){//Consturtor with arguments
//deliberately empty
}