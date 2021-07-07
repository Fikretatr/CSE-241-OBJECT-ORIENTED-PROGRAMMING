#include<iostream>
#include<string>

using namespace std;
#include"Security.h"

int Security::validate(string username,string password){
	//check username and password
	if ((username=="abbott")&&(password=="monday"))
		return 1;
	if ((username=="castello")&&(password=="tuesday"))
		return 2;

	return 0;


}		