#include <iostream>
using namespace std;

class Rational
{
private:
int numerator;   //class variables
int denominator;
public:
Rational()   //default constructor
{}
Rational(int num)
{
numerator = num;
denominator = 1;
}
Rational(int num,int den)
{
numerator=num;
if(den != 0)
denominator=den;
else
cout<<"\nInvaid denominator : should not be 0";
}

Rational operator+(Rational r)
{
Rational temp;
temp.numerator=numerator*r.denominator+r.numerator*denominator;
temp.denominator=denominator*r.denominator;
return temp;
}
     Rational operator-(Rational r)
     {
     Rational temp;
temp.numerator=numerator*r.denominator-r.numerator*denominator;
temp.denominator=denominator*r.denominator;
return temp;
     }
     Rational operator*(Rational r)
     {
     Rational temp;
     temp.numerator=numerator*r.numerator;
     temp.denominator=denominator*r.denominator;
     return temp;
  
     }
     Rational operator/(Rational r)
     {
     Rational temp;
     temp.numerator=numerator*r.denominator;
     temp.denominator=denominator*r.numerator;
     return temp;
     }

void display()
{
cout<<numerator<<"/"<<denominator;
}
bool operator>=(Rational &R2)          //operator function
{
return ( (this->numerator >= R2.numerator && this->denominator ==
R2.denominator) || (this->denominator < R2.denominator &&
this->numerator == R2.denominator));
}
bool operator>=(int num)          //operator function
{
if((this->numerator /this->denominator) >= 0)
   return false;
   else
   return true;
}

bool operator>(Rational &R2)          //operator function
{
return ( (this->numerator > R2.numerator && this->denominator ==
R2.denominator) || (this->denominator < R2.denominator &&
this->numerator == R2.denominator));
}
friend ostream &operator<<( ostream &,const Rational & );
friend istream &operator>>( istream &, Rational &) ;
bool operator== (Rational &R2)          //operator function   
{
return (this->numerator == R2.numerator && this->denominator == R2.denominator);
}
};
ostream &operator<<( ostream &output,const Rational &R ) {
         output <<   R.numerator << "/"<<R.denominator ;
         return output;         
      }

       istream &operator>>( istream &input, Rational &R ) {
         input >> R.numerator >> R.denominator;
         return input;         
      }


int main()
{
Rational n1(1,2), n2, n3;
cout << n1 << endl;
cout<<"Enter Numerator And Denominator Ex: 2 3 : ";
cin >> n2; // Input 2/3
cout << n2 << endl;
cout << n1 + n2 << endl;
cout << n1 - n2 << endl;
cout << n1 * n2 << endl;
cout << n1 / n2 << endl;
if (n1 == n2)
cout << "n1 equals n2" << endl;
else if (n1 > n2)
cout << n1 << " greater than " << n2 << endl;
else
cout << n1 << " less than " << n2 << endl;
cout<<"Enter Numerator And Denominator Ex: 2 3 : ";
cin >> n3; // Input -1/3
cout << n3 << endl;
if(n3 >= 0)
{
cout << n3 << " is positive" << endl;
}
else
{
cout << n3 << " is negative" << endl;
}

return 0;
}