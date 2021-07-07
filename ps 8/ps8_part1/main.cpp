#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
#include "Adminstrator.h"
#include "User.h"
#include "Security.h"

int main(){
int ch;
char ans;
Adminstrator admin;
User user1;
do{
	ans='n';
	//input the number who will login
	cout<<"Login:\n1.Adminstrator\n2.User\n";
	cin>>ch;
	cin.ignore(1000,'\n');
	string uname;
	//Input the username 
	cout<<"Enter the username:\n";
	getline (cin,uname);
	string pword;
	//Input the password
	cout<<"Enter Password\n";
	getline(cin,pword);
	switch(ch){
		//pass the username and password as parameters to
		//login function
		case 1:
		if(admin.login(uname,pword))
			cout<<"Login SUCCESS";
		else
		{
			cout<<"Login Failed";
			cout<<"Please Try Again";
			cout<<"Press y to process";
			cin>>ans;
		}
		break;
		case 2:
		if(user1.login(uname,pword))
			cout<<"Login SUCCESS";
		else
		{
			cout<<"Login Failed";
			cout<<"Please Try Again";
			cout<<"Press y to process";
			cin>>ans;
		}
		break;

	}
}
		while(ans=='y'||ans=='Y');
		std::cin.get();
		return 0;
}