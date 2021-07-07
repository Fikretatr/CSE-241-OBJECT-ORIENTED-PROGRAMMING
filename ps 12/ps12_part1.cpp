#include<iostream>
#include<math.h>
using namespace std;

template <class T>
T absolute(T value1,T value2){
T result=abs(value1-value2);
return result;
}
int main(){
double d1,d2;char a,b;float f1,f2;int i1,i2;
cout << "Enter two int number:\n";
cin>>i1>>i2;
cout <<"The absolute is:"<<absolute(i1,i2) << endl;
cout << "Enter two float number:\n";
cin >>f1>>f2;
cout <<"The absolute is:"<<absolute(f1,f2) << endl;
cout << "Enter two double number:\n";
cin >>d1>>d2;
cout <<"The absolute is:"<<absolute(d1,d2) << endl;
cout << "Enter two chars :\n";
cin >>a>>b;
cout <<"The absolute is:"<<absolute(a,b)<< endl;
return 0;
}