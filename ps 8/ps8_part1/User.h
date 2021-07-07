//Using #ifndef ensures no header files 
//includes more than once

#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
#include"Security.h"
using namespace std;
class User{
	public:
	bool login(string username,string password);

};
#endif
