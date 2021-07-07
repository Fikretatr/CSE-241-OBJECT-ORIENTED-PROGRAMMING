#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>

using namespace std;

const int MAX_DIGIT_COUNT = 9;

int check_value (int number[MAX_DIGIT_COUNT],int size,int r);
int check_repeat (int number[MAX_DIGIT_COUNT],int size,int r);
void create_random(int number[MAX_DIGIT_COUNT],int size);
void print(int number[MAX_DIGIT_COUNT],int size);
void string_to_int(char str[MAX_DIGIT_COUNT],int size,int number[MAX_DIGIT_COUNT]);
int check_int(string str);
int check_place(int number[MAX_DIGIT_COUNT],int size);



int main(int argc,char* argv[]){

int size;/*This variable holds the value of number of digits is taken from the user*/
int counter=1;/*Estimate counter*/
int number[MAX_DIGIT_COUNT];/*This array will have numbers*/
if(argc==3){
	if(strcmp(argv[1],"-r") == 0){
		string numOfdigits = argv[2];
		if(numOfdigits.at(0) <='9' && numOfdigits.at(0) >='1' && numOfdigits.length() == 1){
			size=argv[2][0]-48;
			create_random(number,size);
			//print(number,size);

			while(counter!=100 && size!=check_place(number,size)){/*If player does not find  the number in 100 times, the game ends.&&Location matching and error checking function*/
				counter++;/*This counter counts the number of games played.*/
			}
	
		}
		else{/*Check for any errors in program call.*/
			cout<<"E0"<<endl;
			exit(1);
		}
	}
	else if(strcmp(argv[1],"-u") == 0){
		string str=argv[2];
		size = str.length();
		string_to_int(argv[2],size,number);
		while(counter!=100 && size!=check_place(number,size)){/*If player does not find 100 times, the game ends.&&Location matching and error checking function*/
				counter++;
		}
	}

	if(counter>=100){/*If he does not find 100 times:Fail*/
		cout<<"\nFAILED\n";
	}else{
		cout<<"\nFOUND "<<counter<<endl;/*If check place is return count1*/
}
}else{
		cout<<"E0"<<endl;/*Check for any errors in program call.*/
		exit(1);
	}
return 0;

}

int check_value (int number[MAX_DIGIT_COUNT],int size,int r){/*Function that makes the numbers differ from each other*/

	for(int i=0;i<size;i++){
		if(number[i]==r){
			return 1;
		}

	}
	return 0;


}
int check_repeat (int number[MAX_DIGIT_COUNT],int size,int r){/*The function that checks the number of errors entered by the user.*/
	int flag = 0;
	for(int i=0;i<size;i++){
		if(number[i]==r){
			if(flag!=0)return 1;
			else flag = 1;
		}

	}
	return 0;


}
void create_random(int number[MAX_DIGIT_COUNT],int size){/*This function generates a random number*/
	srand( (unsigned int)time(NULL) );

	for(int i=0;i<size;i++){
		int r=rand()%10;
		if(r==0&&i==0){/*If first digit is 0 turn back*/
			i--;	
		}
		else{
			if(check_value(number,i,r)==1&&i>0){/*repeat control*/
				i--;
			}
			else{
				number[i]=r;
			}
			
		}	
	}
	


}
/*void print(int number[MAX_DIGIT_COUNT],int size){/*This function print numbers array
	for(int i=0;i<size;i++){
		cout<<number[i];
	}
	cout<<endl;

}*/
void string_to_int(char str[MAX_DIGIT_COUNT],int size,int number[MAX_DIGIT_COUNT]){/*This function convert string to int and check the error control*/
	for(int i=0;i<size;i++){
		char a[1] = {str[i]};
		int r=atoi(a);
		if(str[0] =='-' || (r==0&&i==0)){/*If number is negative or strats with zero;error 0*/
			cout<<"E0"<<endl;
			exit(1);
		}
		else{
			if(check_value(number,i,r)==1&&i>0){/*Function that makes the numbers differ from each other*/
				cout<<"E0"<<endl;/*Numbers should be differ with each other*/
				exit(1);
			}
			else{
				number[i]=r;/*If no error numbers are ok*/
			}
		}	
	}
}
int check_int(string str){/*Inputs must be number*/
		for(int i=0;i<str.length();i++){
			if(str[i]<48||str[i]>57){
				return 1;
			}

		}
		return 0;
	}
int check_place(int number[MAX_DIGIT_COUNT],int size){/*Location matching and error checking function*/
 	string str;
 	int count1=0,count2=0;
 	cout<<"Enter Number:"<<endl;
 	cin>>str;
 	int temp[size];
 	for(int i=0;i<str.length();i++){
 		temp[i] = str[i] -48; /*Converting character array to int array*/
 		if(temp[0] == 0){/*First digit should not be 0*/
			cout<<"E1"<<endl;
			exit(1);	
 		}	
 	}
 	for(int i=0;i<str.length();i++){
 		if(check_repeat(temp,size,temp[i])==1){/*The numbers entered by the user must be different from each other*/
 			cout<<"E1"<<endl;
			 exit(1);
 		}
 	}
 	if(size!=str.length()){/* If user enters a number which has more or less than number of digits, program should print the error1 message and exit. */
 		cout<<"E1"<<endl;
 		exit(1);
 	}
 	else if(check_int(str)==1){/*If the user enters something but not an integer, your program should print error2*/
 		cout<<"E2"<<endl;
 		exit(1);
 	}
 	else{
 		for(int k=0;k<str.length();k++){/*In this cycle, match control is done.*/
 			
 			for(int j=0;j<size;j++){
 				if(str[j]==number[k]+48){
 					
 					if(j==k){
 						count1++;/* The count of digits of the proposed number that match in place of the secret number.*/
 					}
 					else
 						count2++;/* The count of digits of the proposed number which do exist in the secret number but are not in place. */
 			}
 			}
 			
 		}
 		cout<<count1<<" "<<count2<<endl;

 	}
 	return count1;
 }	