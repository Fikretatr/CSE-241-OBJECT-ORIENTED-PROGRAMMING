//		    																			//
//	****** Iterative Version Of The Recursive Function In The Previous Project*******	//
//																						//

#include <iostream>

using namespace std;

int func_Len(char* str);//For length of a string using recursion
void Arr(char[], int index1, int index2);
void reverse_string(char[]);

int main()
{
	//a[1] == 'A' a[2] == 'B' a[3] == 'C' a[4] == 'D' a[5] == 'E' 
	//a[1] == 'A' a[2] == 'E' a[3] == 'D' a[4] == 'C' a[5] == 'B'

	char str[] = {'A', 'B', 'C', 'D', 'E', '\0'};
	char name[] = "FENERBAHCE";

	cout << "\nChar array: " << str << "\n";
	 
	Arr(str, 1, 4);

	cout << "After reversing with indexes (1, 4): " << str << " \n"<<endl;

	cout << "String: " << name;

	reverse_string(name);

	cout << "\nAfter reversing: " << name<<endl; 

return 0;

}

//The function is reversing the order of those entries in the array whose indexes are
//between the two bounds.

void Arr(char str[], int index1, int index2){
	
	int size;
	char temp;
	size = func_Len(str);//Finding length

	//After i have fully debugged this function
	if(index1 < 0 || index2 >= size){//CONTROL index
	cout << "Invalid indexes";
	return;
	}		
	for(int i=0;index1 <=index2;i++){
		
		temp=str[index1]; 				// S  
    	str[index1]=str[index2];		//	W
    	str[index2]=temp;				//	 A
    									//	  P
    	index1 ++;
    	index2 --;
	}
}
//This function includes a call to the
//definition that i did 

void reverse_string(char str[]){//Function that reverses the string

int INDEX1 = 0,	INDEX2 = func_Len(str)-1;

Arr(str, INDEX1, INDEX2 );

}


int func_Len(char str[])//Find length  
{  
	int i;
   for(i=0;str[i] != '\0';i++){

   }
   	return i;
    
    
} 