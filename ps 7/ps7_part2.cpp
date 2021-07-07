#include <iostream>
using namespace std;

class Student{

public: 
        Student();// Constructor 
        ~Student();// Destructor 
        void DataInput();//  Input Function
        void DataOutput();//  Output Function
        void ResetClass();//  reset function
        Student& operator =(Student& assignment);// Overloaded Assignment Operator

private:
        string Name;
        int numClasses;
        string *classList;

};

int main(){
Student std1, std2;

std1.DataInput();
cout << "Std1's information:" << endl;
std1.DataOutput();
cout << endl;

std2 = std1;
cout << "Overloaded assignment operator makes a new copy(std2 from std1):" << endl;
std2.DataOutput();
cout << endl; 
std1.ResetClass();
cout << "Std1's information after reset function:" << endl;
std1.DataOutput();
cout << endl; 
cout << "Std2's information should be original data:" << endl;
std2.DataOutput();
cout << endl;

return 0;
}

void Student::DataInput(){

            ResetClass();
                cout << "Student name: ";
            getline(cin, Name);
                cout << "Number of classes: ";
                cin >> numClasses;
                cin.ignore(2,'\n');//If ignore is not entered before the getline command, a and b are written on the same line. 
                //Ignore must be used before getline command.

            if (numClasses > 0){

                classList = new string[numClasses];

            for (int i=0; i<numClasses; i++){

                cout << "Name of the class " << (i+1) << " : ";
                getline(cin, classList[i]);

        }
    }
            cout << endl;
}

void Student::DataOutput(){

    cout << endl<< "List of Class: " << endl;

    for (int i = 0; i < numClasses; i++){
            cout << i + 1 << ") " << classList[i] << endl;
    }
}
Student::Student() : Name(""), numClasses(0), classList(NULL){
    //Constructor 
}
Student::~Student(){//Deconstructer
    numClasses = 0;
    ResetClass();
    Name = "";
}
void Student::ResetClass(){//Reset Function

    if (classList){
        delete [] classList;
        classList = NULL;
        numClasses = 0;
    }
}
Student& Student::operator =(Student& assignment){// Overloaded Assignment Operator 

            ResetClass();
            numClasses = assignment.numClasses;
            
            if (numClasses > 0){
            classList = new string[numClasses];
            
            for (int i = 0; i < numClasses; i++){
            classList[i] = assignment.classList[i];

        }

    }
            return *this;
}