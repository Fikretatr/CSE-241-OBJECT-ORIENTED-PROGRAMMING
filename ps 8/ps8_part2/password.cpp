#include<iostream>
#include<string>
using namespace std;
#include "password.h"
namespace
{
	  string password;
	  int count;

	  bool isvalid1()
	  {
	  	 int count=0;
	  	 if (password.length()==8)
	  	 	    for(int i=0;i<password.length(); i++)
	  	 	    {
	  	 	    	   if((password[i]>='a'&&password[i]<='z')
	  	 	    	   ||password[i]>='A'&&password[i]<='Z')
	  	 	    	   	     count++;
	  	 	    }

	  	 	if(count>0&&count<8)
	  	 	     return true;
	  	 	 else
	  	 	     return false;

	  }
}
namespace Authenticate
{

	void inputPassword()
	{ 
		do
		{

			cout<<"Enter your password(at least 8 characters and at least one non-letter)"<<endl;
			cin>>password;
		}while (!isvalid1());
	}

	string getPassword()
	{

	      return password;


	}     
}