#include<iostream>

using namespace std;

int main() 
{
	string str;// Initialize c-string
	char *head,*tail,temp;// Initialize pointers and char temp
	int i = 0;
	
	cin>>str;//Get str
	
	head = &str[0];// Setting head to the first character.
	tail = &str[str.size() - 1]; // Setting tail to the last character.
//Swap loop	
while (i <= (str.size() - 1)/2)
    {
		temp = *head;
		str[i] = *tail;
		*tail = temp;
		*tail--;//decrement “tail”
		*head++;//increment “head”
		i++;//increment “i" for loop
	}

	cout << str << endl;//Print str
 
    return 0;
}