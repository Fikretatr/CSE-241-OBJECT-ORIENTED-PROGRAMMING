#include<iostream>
#include<string>
using namespace std;
#include"user.h"
namespace
{

	string username;
	bool isvalid(){
		int count=0;
		if(username.length()==8)
			for(int i=0;i<username.length();i++){
				if((username[i]>='a'&&username[i]<='z')
					||username[i]>='A'&&username[i]<='Z')
					count++;
					
			}
			if(count==8)
				return true;
			else 
				return false;

		
		
	}
}


namespace Authenticate
 {


 	    void inputUserName()
 	    {

 	    	do
 	    	{

 	    		cout<<"Enter your username (8  letters only)"<<endl;
 	    		cin>>username;
 	    	}
 	    	while (!isvalid())	;

       }

        string getUserName()

       {
       	return username;

       }
    } 