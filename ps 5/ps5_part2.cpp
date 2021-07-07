#include <iostream>

using namespace std;

class MyInteger{
    
		public:
		//if need constructers	
    	//MyInteger();
    	//MyInteger (int A);
    	int getValue (){return value;};
		void setValue (int inputValue);
    	int operator [] (int index); // Member Function
    
   		private:
    	int value;
    	int a[10];
    
};
//main function
int main(){
	int digit;
	MyInteger x;
	cout<<"Enter Digits:";
	cin>>digit;
	x.setValue(digit);
	//display values 
	for(int i=0;i<10;i++){
		cout<< x[i]<<"  >>  "<<"x["<<i<<"]"<<endl;
	}
	
	return 0;
}

/*
MyInteger::MyInteger(){
	value=0;
}

MyInteger::MyInteger (int A){
    value = init;
}
*/
//sets function
void MyInteger::setValue(int inputValue){
    
    value = inputValue;
    
}
//opertor [] overloading
int MyInteger::operator [] (int index){
	//if digit is:0,exit from program
	if(value==0){
		exit(0);
	}
	//last digit of input value is stored in a[0]
	if(index==0){
		a[0]=value%10;
		return a[0];
	}
	//digits is stored in array 
	else{
		value=value/10;
		a[index]=value%10;
	//last element of array assign -1	
	if(value==0&&a[index]==0){
		a[index]=-1;
		
	}
	return a[index];
	}
	
}