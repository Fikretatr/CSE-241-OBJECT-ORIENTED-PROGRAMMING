#include<iostream>


using namespace std;

class CharPair{
public:
CharPair();
CharPair(int x);
CharPair(int x,char a[]);
int get_size(){return size;};
char& operator[](int index);

private:

char arry[100];
int size;	

};
int main(){
	CharPair a;
	int bsize,csize;
	cout<<"Displays the values of object b:\n";
	for(int i=0;i<a.get_size();i++)
		cout<<a[i]<<endl;

		cout<<"Enter size of array:";
		cin>>bsize;
		cout<<endl;

		CharPair b(bsize);
		cout<<"Displays the values of object b:"<<endl;
		for(int i=0;i<b.get_size();i++)
			cout<<b[i]<<endl;

		
		char array1[20];
		cout<<"Enter the size of array:";
		cin>>csize;
		cout<<endl;
		CharPair c(csize,array1);
		cout<<"Displays the array1 values:\n";
		if(c.get_size()<=sizeof(array1))
			for(int i=0;i<c.get_size();i++)
				cout<<array1[i]<<endl;
		
			
		else{
			cout<<"\nIndex out of range";
			exit(0);

		}		
			cin.get();
			return 0;
			
		
	}

CharPair::CharPair():size(10){
	for(int i=0;i<size;i++)
		arry[i]='#';
}
CharPair::CharPair(int n):size(n){
	for(int i=0;i<size;i++)
		arry[i]='#';
}

CharPair::CharPair(int x,char arr[]){
	size=x;
	for(int i=0;i<size;i++){
		arry[i]='#';
	}
	for(int i=0;i<size;i++){
		arr[i]=arry[i];
	}
}
char& CharPair::operator[](int index){
	if(index>=size){
		cout<<"Illegal index value.\n";
		exit(0);
	}
	return arry[index];
}