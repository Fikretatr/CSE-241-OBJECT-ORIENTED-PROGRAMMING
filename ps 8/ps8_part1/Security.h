//Using #ifndef ensures no header files 
//includes more than once
#ifndef SECURITY_H
#define SECURITY_H
#include<iostream>
#include<string>
using namespace std; 
class Security
{
public:
	static int validate(string username,string password);

};
#endif