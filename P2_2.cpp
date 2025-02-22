#include <iostream>
#include <string.h>
using namespace std;

class student{
    private:
        int rollNumber,marks[3];
        char name[15];

    public:
        student()
        {   int i;
            rollNumber=0;
            strcpy(name,"N/A");
             for(i=0;i<3;i++)
            {
                marks[i]=0;
            }
        }
        
        student(char n[],int rn,int m[])
        {
            strcpy(name,n);
            rollNumber=rn;
            int i;
            for(i=0;i<3;i++)
            {
                marks[i]=m[i];
            }
        }
        
        void displayDetails();
        void calculateAverage();
};

void student::displayDetails()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Roll No: "<<rollNumber<<endl;
    int i;
    for(i=0;i<3;i++)
    {
        cout<<"Marks for subject "<<i+1<<": "<<marks[i]<<endl;
    }
}

void student::calculateAverage()
{
    float avg;
    int i,sum=0;
    for(i=0;i<3;i++)
    {
        sum+=marks[i];
    }
    avg=(float)sum/3;
    cout<<"Average marks: "<<avg<<endl;
}
int main()
{
    student s[25];
    int rn,m[3];
    char nm[15];
    int i,n;
    cout<<"Enter the number of students: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nENTER THE DETAILS FOR STUDENT "<<i+1<<endl;
        cout<<"Enter name: ";
        cin>>nm;
        cout<<"Enter Roll number: ";
        cin>>rn;
        for(int j=0;j<3;j++)
        {
            cout<<"Enter marks for subject "<<j+1<<": ";
            cin>>m[j];
        }
        s[i]=student(nm,rn,m);
    }

    for(i=0;i<n;i++)
    {
        cout<<"\nDATA OF STUDENT "<<i+1<<endl;
        s[i].displayDetails();
        s[i].calculateAverage();
    }
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}