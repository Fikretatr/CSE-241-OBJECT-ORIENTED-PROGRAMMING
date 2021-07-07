#include<iostream>
#include<string>

using namespace std;

#include"User.h"
#include"Security.h"

bool User::login(string username,string password){
	int valid=Security::validate(username,password);
	if((valid==1)||(valid==2))
		return true;
	return false;
}