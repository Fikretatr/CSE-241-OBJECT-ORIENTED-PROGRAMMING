#include<iostream>
#include<string>
using namespace std;
#include"Security.h"
#include"Adminstrator.h"

bool Adminstrator::login(string username,string password){
	int valid=Security::validate(username,password);
	if(valid==2)

	return true;
	return false;
}