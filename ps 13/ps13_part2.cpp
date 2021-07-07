#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class NameNotFound
{
public:
	NameNotFound(string sName):name(sName){}
	string getName(){return name;}
private:
	string name;
};


class Account
{
private:
double balance;
public:
Account()
{
balance = 0;
}
Account( double initialDeposit)
{
balance = initialDeposit;
}
double getBalance()
{
return balance;
}
// returns new balance or -1 if error
double deposit( double amount)
{
if (amount > 0)
balance += amount;
else
throw NameNotFound("deposit can not negative");
return balance;
}
// returns new balance or -1 if invalid amount
double withdraw( double amount)
{
if ((amount > balance) || (amount < 0))
throw NameNotFound("balance can not be more withdraw ");
else
balance -= amount;
return balance;
}
};

int main(){
    try{
        Account a(1000);
        a.deposit(-80);
    }catch(NameNotFound& e){
        cout<<e.getName()<<endl;
    }try{
        Account b(1000);
        b.withdraw(5000);
    }catch(NameNotFound& e1){
        cout<<e1.getName()<<endl;

    }

}