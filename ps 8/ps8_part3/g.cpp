#include<iostream>

using namespace std;
#include "g.h"

namespace Ab  
{

	void g()
    {     

    	 int a,b;
         
    	 cout<<"enter number:";
    	 cin>>a;
    	 b=a*a*a;

    	 cout<<"g() of namespace Ab is called\n";
    	 cout<<"the cube of "<<a<<"is: "<<b<<"\n";

    }

}