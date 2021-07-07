#include <iostream>

using namespace std;

int recLen(char* str);//For length of a string using recursion
void recArr(char[], int index1, int index2);
void reverse_string(char[]);


int main()
{
	//a[1] == 'A' a[2] == 'B' a[3] == 'C' a[4] == 'D' a[5] == 'E' 
	//a[1] == 'A' a[2] == 'E' a[3] == 'D' a[4] == 'C' a[5] == 'B'

	char str[] = {'A', 'B', 'C', 'D', 'E', '\0'};
	char name[] = "FENERBAHCE";

	cout << "\nChar array: " << str << "\n";
	 
	recArr(str, 1, 4);

	cout << "After reversing with indexes (1, 4): " << str << " \n"<<endl;

	cout << "String: " << name;

	reverse_string(name);

	cout << "\nAfter reversing: " << name<<endl; 

return 0;

}
//The function is reversing the order of those entries in the array whose indexes are
//between the two bounds.

void recArr(char str[], int index1, int index2){
	int size;
	char temp;
	size = recLen(str);//Finding length

	//After i have fully debugged this function
	if(index1 < 0 || index2 >= size){//CONTROL index
	cout << "Invalid indexes";
	return;
	}		

	if (index1 >=index2)
        return;
									//S    
    temp=str[index1]; 				// W   
    str[index1]=str[index2];		//	A
    str[index2]=temp;				//	 P

    recArr(str, index1 + 1, index2 - 1);
	

	}
//This function includes a call to the
//recursive definition i did 

void reverse_string(char str[]){//Function that reverses the string

int INDEX1 = 0,	INDEX2 = recLen(str)-1;

recArr(str, INDEX1, INDEX2 );

}


int recLen(char* str)//Find length using recursive func   
{  
    // if we reach at the end of the string 
    if (*str == '\0')  
        return 0; 
    else
        return 1 + recLen(str + 1);  
} 