#include<iostream>
using namespace std;
//A class named PrimeNumber that stores a prime number.
class PrimeNumber{
public:
  //The default constructor should set the prime number to 1.  
    PrimeNumber();
    PrimeNumber(int input_value);
    void set(int input_value);
    int get(){return value;};
    int operator ++();
    int operator --();
    
private:
  int value;
  int prime_control(int value);  
}; 
//Main function
int main(){
   
    PrimeNumber p_number1,p_number2(29);
    //testing class
    
    //testing ++
    cout<<"operator overload (++)"<<endl;
    cout<<p_number1.get()<<endl;
    PrimeNumber p_number3 = ++p_number1;
    cout << p_number3.get() << endl;
    PrimeNumber p_number5 = ++p_number3;
    cout << p_number5.get() << endl;
    //testing --
    cout<<"operator overload (--)"<<endl;
    cout<<p_number2.get()<<endl;
    PrimeNumber p_number4 = --p_number2;
    cout << p_number4.get() << endl;
    PrimeNumber p_number6 = --p_number4;
    cout << p_number6.get() << endl;
    return 0;
}

//prime number control
int PrimeNumber::prime_control(int value){
    int flag=0;
    for(int i=2;i<value;i++){
        if(value%i==0){
            flag=1;
        }
    }
    if(flag==1){
        return 0;
    }
    else 
        return 1;
}

//The default constructor should set the prime number to 1
PrimeNumber::PrimeNumber(){
    value=1;
}//The constructor 
PrimeNumber::PrimeNumber(int input_value){
    value=input_value;
}

//Set Function
void PrimeNumber::set(int input_value){
    value=input_value;
}

//Overloading ++
int PrimeNumber::operator ++(){
        int num=value;
    while(1){
        num++;
        if(prime_control(num)==1){
            return num;
        }

    }

}

//Overloading ++
int PrimeNumber::operator --(){
        int num=value;
    while(1){
        num--;
        if(prime_control(num)==1){
            return num;
        }

    }

        
}    