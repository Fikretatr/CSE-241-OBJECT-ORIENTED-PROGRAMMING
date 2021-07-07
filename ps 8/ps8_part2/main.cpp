#include<iostream>

using namespace std;
#include "user.h"
#include "password.h"




using namespace Authenticate;

int main()
{

	  inputUserName();
	  inputPassword();

	  cout<<"your name is "<<getUserName()<<" and your password is: "<<getPassword()<<endl;
	      return  0;

	      
}