//Using #ifndef ensures no header files 
//includes more than once
#ifndef ADMINSTRATOR_H
#define ADMINSTRATOR_H

#include<iostream>
#include<string>

#include"Security.h"

using namespace std;
class Adminstrator
{
public:
	bool login (string username, string password);

};
#endif