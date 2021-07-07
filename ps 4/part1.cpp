#include<iostream>
using namespace std;

class Grade {   /*created class*/
    public:

        void setQuiz_1(double grade);
        void setQuiz_2(double grade);
        void setMidterm(double grade);
        void setFinal(double grade);
        double getQuiz_1(){return quiz1;};
        double getQuiz_2(){return quiz2;};
        double getMidterm(){return midterm;};
        double getFinal(){return final;};
        double clacAvg();
        char calcLG();
        
    private:
        double quiz1,quiz2;
        double midterm, final;
        double average;
        char letterGrade;
};

struct Student
{
    int ID;
    Grade grade;
};


int main(){
    Grade grade;
    Student students[5];

    for(int i=0;i<5;i++){
        students[i].ID = i;
    }

    students[0].grade.setQuiz_1(7);
    students[0].grade.setQuiz_2(10);   
    students[0].grade.setMidterm(90);
    students[0].grade.setFinal(95);

    cout<<students[0].grade.calcLG()<<endl; /*calculate the student's average*/

    students[1].grade.setQuiz_1(9);
    students[1].grade.setQuiz_2(8);   
    students[1].grade.setMidterm(90);
    students[1].grade.setFinal(80);

    cout<<students[1].grade.calcLG()<<endl; /*calculate the student's average*/


    students[2].grade.setQuiz_1(7);
    students[2].grade.setQuiz_2(8);   
    students[2].grade.setMidterm(70);
    students[2].grade.setFinal(80);

    cout<<students[2].grade.calcLG()<<endl; /*calculate the student's average*/


    students[3].grade.setQuiz_1(5);
    students[3].grade.setQuiz_2(8);   
    students[3].grade.setMidterm(50);
    students[3].grade.setFinal(70);

    cout<<students[3].grade.calcLG()<<endl; /*calculate the student's average*/


    students[4].grade.setQuiz_1(4);
    students[4].grade.setQuiz_2(0);   
    students[4].grade.setMidterm(40);
    students[4].grade.setFinal(35);

    cout<<students[4].grade.calcLG()<<endl; /*calculate the student's average*/



    return 0;
}

void Grade::setQuiz_1(double grade){    /*function taking quiz1 grade*/
    quiz1 = grade;

}


void Grade::setQuiz_2(double grade){    /*function taking quiz2 grade*/
    quiz2 = grade;
}

void Grade::setMidterm(double grade){   /*function taking midterm grade*/
    midterm = grade;
}


void Grade::setFinal(double grade){     /*function taking final grade*/
    final = grade;
}

double Grade::clacAvg(){  /*average calculation*/
    double tempQ1,tempQ2;


    tempQ1 = (getQuiz_1())*10;
    tempQ2 = (getQuiz_2())*10;
    
   

    double Qavg = (tempQ1+tempQ2)/2;

    average = getFinal()*0.5 + getMidterm()*0.25 + Qavg*0.25;   /*average calculation*/
    cout<<"Average:"<<average<<"\nLetterGrade:";
    return average;
}

char Grade::calcLG(){   /*create letterGrade*/
    double avg = clacAvg();

    if(avg<60) return letterGrade = 'F';
    if(avg<70 && avg>=60) return letterGrade = 'D';
    if(avg<80 && avg>=70) return letterGrade = 'C';
    if(avg<90 && avg>=80) return letterGrade = 'B';
    if(avg<=100 && avg>=90) return letterGrade = 'A';

    return 'z';
}
