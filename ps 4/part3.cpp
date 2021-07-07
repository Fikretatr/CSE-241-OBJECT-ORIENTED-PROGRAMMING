#include <iostream>

using namespace std;

class Point 	/* A class named Point */
{
	public:
		void setX(int Xlocation);
		void setY(int Ylocation);
		void movepoint(int x, int y);
		void rotate90();
	
	const int getX();
	const int getY();
	
	private:
		int xloc;
		int yloc;	
};
	

	int main()
	{
	Point mypoint;

	int x, y;

	cout << "Enter the x coordinate: ";
	cin >>x;
	
	cout << "Enter the y coordinate: ";
	cin >>y;

	mypoint.setX(x);	/*Get X AND Y CORDINATE*/
	mypoint.setY(y);

	cout<< "Point is: "<< mypoint.getX() << "," << mypoint.getY() << endl;
	
	cout<<"A member function to rotate the point by 90 degrees clockwise around the origin:";
	mypoint.rotate90();
	cout<<mypoint.getX() << "," << mypoint.getY()<< endl;

	cout<< "The point is moved 2 units in right diagonal:\n";
	mypoint.movepoint(2,2);
	cout<< mypoint.getX() << "," << mypoint.getY()<< endl;

	return 0;
}

void Point::setX(int Xlocation){	/*Get X AND Y CORDINATE*/
xloc = Xlocation;
}

void Point::setY(int Ylocation){	/*Get X AND Y CORDINATE*/
yloc =Ylocation;
}

const int Point::getX(){	
	return xloc;
}

const int Point::getY(){
	return yloc;
}

void Point::movepoint(int x, int y){	/*Point is moved*/
	yloc += y;
	xloc += x;
	}

void Point::rotate90(){	/* Rotate 90 degrees clockwise around the origin */
	int tempx,tempy;

	tempx = xloc;
	tempy = yloc;
	xloc= tempy;
	yloc = -tempx;
}
