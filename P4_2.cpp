#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public:
        Person(){};
        Person(string n,int a)
        {
            name=n;
            age=a;
        }
        void displayPerson()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
};

class Employee: public Person{
    protected:
        int EmployeeID;
    public:
        Employee():Person(){};
        Employee(string n,int a,int eId):Person(n,a){
            EmployeeID=eId;
        }
        void displayEmployee()
        {
            displayPerson();
            cout<<"Employee ID: "<<EmployeeID<<endl;
        }
};

class Manager: public Employee{
    protected:
        string Department;
    public:
        Manager():Employee(){};
        Manager(string n,int a,int eId,string d):Employee(n,a,eId){
            Department=d;
        }
        void displayManager()
        {
            displayEmployee();
            cout<<"Department: "<<Department<<endl;
        }
};

int main()
{
    string n,d;
    int a,eId;

    int i,choice,count=0;
    Manager* Emp[15];

    program:
          cout<<"Enter name: ";
          cin>>n;
          cout<<"Enter age: ";
          cin>>a;
          cout<<"Enter employee Id: ";
          cin>>eId;
          cout<<"Enter Department: ";
          cin>>d;

          Emp[count] = new Manager(n,a,eId,d);
          count++;

          cout<<"Do you want to add more Employee?(1 for yes/0 for no)\n";
          cout<<"Enter your choice: ";
          cin>>choice;

          if(choice!=1)
          {
            cout<<"Displaying details of employee\n"<<endl;
            for(i=0;i<count;i++)
            {
                cout<<"EMPLOYEE "<<i+1<<endl;
                Emp[i]->displayManager();
            }
            return 0;
          }

          else{
            goto program;
          }
          cout<<"Anshkumar Darji - 24CE022"<<endl;
          return 0;
}
