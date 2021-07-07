#include <iostream>
using namespace std;

int Fibonacci(int n);

int main()
{
    cout << "Which Fibonacci Number Do You Want?\n";
    
    int WHICH_NUMBER;
    
    cin >> WHICH_NUMBER;
    //The Fibonacci numbers are F0 is 1, F1 is 1, F2 is 2, F3 is 3, F4 is 5
    cout << "F"<<WHICH_NUMBER<<" is "<<Fibonacci(WHICH_NUMBER)<< endl;

    return 0;

}

int Fibonacci(int n)//recursive function
{
    if(n < 2 )

        return n;

    else

        return Fibonacci(n - 1) + Fibonacci(n - 2);//Fi+2 = Fi + Fi+1 for i = 0, 1, 2, ...
}
