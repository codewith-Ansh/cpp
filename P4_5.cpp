#include<iostream>
using namespace std;

class Student {
protected:
    float marks;
public:
    void setMarks(float m){
        marks=m;
    }
    virtual char computeGrade()=0;
};

class Undergraduate:public Student {
public:
    char computeGrade(){
        if(marks>=85)
            return 'A';
        else if(marks>=70)
            return 'B';
        else if(marks>=55)
            return 'C';
        else if(marks>=40)
            return 'D';
        else 
            return 'F';
    }
};

class Postgraduate:public Student {
public:
    char computeGrade(){
        if(marks>=90)
            return 'A';
        else if(marks>=75)
            return 'B';
        else if(marks>=60)
            return 'C';
        else if(marks>=50)
            return 'D';
        else 
            return 'F';
    }
};

int main(){
    Student*students[20];
    int count=0,choice;
    float marks;
    char more;

    do{
        cout<<"Enter student type(1=Undergraduate,2=Postgraduate):";
        cin>>choice;

        if(choice==1){
            students[count]=new Undergraduate();
            cout<<"Enter marks for student "<<count+1<<":";
            cin>>marks;
            students[count]->setMarks(marks);
            count++;
        } else if(choice==2){
            students[count]=new Postgraduate();
            cout<<"Enter marks for student "<<count+1<<":";
            cin>>marks;
            students[count]->setMarks(marks);
            count++;
        } else {
            cout<<"Enter valid input!"<<endl;
        }

        cout<<"Do you want to add another student?(y/n):";
        cin>>more;
        cout<<endl;

    }while(more=='y'||more=='Y');

    cout<<"\n---Student Grades---\n";
    for(int i=0;i<count;i++){
        cout<<"Student "<<i+1<<":Grade="<<students[i]->computeGrade()<<endl;
    }

    for(int i=0;i<count;i++){
        delete students[i];
    }
    cout<<"Anshkumar Darji-24CE022"<<endl;
    return 0;
}