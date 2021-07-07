#include<iostream>
#include<tgmath.h>     
using namespace std;

void Hanoi(int disk,char source,char C,char intermediate);//Recursive Function

int main(){
	int disk;
	cout<<"How many disks do you want? "<<endl<<"Number of Disk:"; 
	cin>>disk;
	Hanoi(disk,'A','C','B');//Call function
	cout<<"For "<<disk<<" disks, total "<<pow (2, disk)-1<<" moves are required."<<endl;//Number of moves
	return 0;
}



void Hanoi(int disk,char source,char destination,char intermediate){
	
		//The terminal state is the state
		// where we are not going to call this function anymore.
		if(disk==1){ //The terminal 

		cout<<"Disk "<<disk<<" moving from "<<source<<" to "<<destination<<endl;
		
		}

		else
		{
		//Now we call our function again by passing these arguments. 
		//In that case, we divide the stack of disks in two parts. 
		//The largest disk (nth disk) is in one part and all other (n-1) disks are in the second part.
		
		Hanoi(disk-1,source,intermediate,destination);  
		//As we said we pass total_disks_on_stack — 1 as an argument. 
		//And then again we move our disk like this:
		cout<<"Disk "<<disk<<" moving from "<<source<<" to "<<destination<<endl;
		//After that we again call our method like this:
		Hanoi(disk-1,intermediate,destination,source);
	}
}

