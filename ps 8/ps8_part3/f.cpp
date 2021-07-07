#include<iostream>

using namespace std;

#include  "f.h"

namespace Ab
{
	   void f()
       {
           int  a,b;

           cout<<"enter number:";
           cin>>a;
           b=a*a;

           cout<<"f() of namespace Ab is called\n";
           cout<<"the square of "<<a<<"is: "<<b<<"\n";
        }
   }