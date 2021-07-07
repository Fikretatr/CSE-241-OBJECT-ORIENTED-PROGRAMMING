#include<iostream>

using namespace std;

class Vector2D{

public:
Vector2D();	
Vector2D(int newx, int newy);
void set(int comp_x,int comp_y);
int get(){return x;}//get Function
int get2(){return y;}//get Function
int operator *(Vector2D Vector2);
private:
int x,y;

};

int main(){
	Vector2D Vector1(2,4),Vector2(3,5),Vector3(0,-1);
	//Test vectors
	cout<<"("<<Vector1.get()<<","<<Vector1.get2()<<")"<<"*"<<"("<<Vector2.get()
	<<","<<Vector2.get2()<<")"<<"="<<Vector1*Vector2<<endl;
	
	cout<<"("<<Vector2.get()<<","<<Vector2.get2()<<")"<<"*"<<"("<<Vector3.get()
	<<","<<Vector3.get2()<<")"<<"="<<Vector2*Vector3;

}
// Default Constructor
Vector2D::Vector2D(){
x=0;
y=0;
}
//Constructor to initialize x,y
Vector2D::Vector2D(int comp_x , int comp_y){
x=comp_x;
y=comp_y;
}
//Set Function
void Vector2D::set(int comp_x,int comp_y){
x=comp_x;
y=comp_y;
}
//Overload * to compute the dot product
int Vector2D::operator *(Vector2D Vector2){
	return (x*Vector2.x)+(y*Vector2.y);

}
