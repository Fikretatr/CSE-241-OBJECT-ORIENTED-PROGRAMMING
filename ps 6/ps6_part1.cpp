#include<iostream>  
using namespace std;

class complex  
 {  
  
 public:  
 	complex();
 	complex(double,double);
 	complex operator +(complex c2);
 	complex operator -(complex c2);
 	complex  operator *(complex c2);
 	complex  operator /(complex c2) ;
 	friend ostream & operator << (ostream &out, const complex &c2);
 	friend istream & operator >> (istream &in,  complex &c2);
 	bool operator ==(complex);
 	void set(double r,double i);
 	int get(){return real;}//get Function
	int get2(){return imag;}//get Function
 private:
 	 double real;               
   double imag; 

 };


 int main(){
 	complex a(1.0,-2.0); // Calls Constructor
 	complex b(2.0,-2.0);
 	

   complex d,e,c;
   cout<<"Please enter Complex Number A"<<endl;
   cin>>e;// Calls overloaded >> operator
   cout<<"Please enter Complex Number B"<<endl;
   cin>>c;// Calls overloaded >> operator

   if(e==c)            // calls overloaded == operator
      cout<<"A==B"<<endl;
      else
      cout<<"A!=B"<<endl;

   cout<<"A+B:"<<endl;
   d=e+c;   // Calls overloaded + operator

   cout<<d<<endl; // Calls overloaded << operator
   cout<<"A-B:"<<endl;
   d=e-c;     // Calls overloaded - operator

   cout<<d<<endl;// Calls overloaded << operator
   cout<<"A*B:"<<endl;
	 d=e*c;        // calls overloaded * operator

   cout<<d<<endl;// Calls overloaded << operator
   cout<<"A/B:"<<endl;
	 d=e/c;        // calls overloaded / operator

   cout<<d<<endl; // Calls overloaded << operator

	     return 0;
 }
 
 complex::complex(){
 	  real=0;               // Real Part
    imag=0;
 }
 complex::complex(double x,double y){
 	real=x;
 	imag=y;
 }
 complex complex::operator +(complex c2)  
 {  
 complex c3;  
 c3.real= real+c2. real;  
 c3.imag=imag+c2.imag; 

 return c3;  
 }  

 complex complex::operator -(complex c2){  
 complex c3;  
 c3.real=real-c2.real;  
 c3.imag=imag-c2.imag;  
 return c3;  
 }

 complex complex::operator *(complex c2){  
 complex c3;  
 c3.real=(real*c2.real)-(imag*c2.imag);  
 c3.imag=(imag*c2.real)+(real*c2.imag);  
 return c3;  
 }  

 complex complex::operator /(complex c2){  
 complex c3;  
 c3.real=((real*c2.real)+(imag*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));  
 c3.imag=((imag*c2.real)-(real*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));  
 return c3;  
 }  

 ostream & operator << (ostream &out, const complex &c2){
    out << c2.real;
    out << "+" << c2.imag<<"i" << endl;
    return out;
}

istream & operator >> (istream &in, complex &c2){
    cout << "Enter Real Part: ";
    in >> c2.real;
    cout << "Enter Imagenory Part: ";
    in >> c2.imag;
    
    return in;
}

bool complex::operator ==(complex c){
             return (real==c.real)&&(imag==c.imag) ? 1 : 0;
    }
void complex::set(double r,double i) {
               real=r;
               imag=i;
  }