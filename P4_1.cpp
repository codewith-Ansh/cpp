#include <iostream>
using namespace std;
#define PI 3.14

class shape{
    protected:
        float radius;
    public:
        shape(float r)
        {
            radius=r;
        }
};

class circle: public shape{
    private:
        float area;
    public:
        circle(float r):shape(r){}

        void calculateArea(){
            area=PI*radius*radius;
            cout<<"Area of circle: "<<area<<endl;
        }
};

int main()
{
    circle* c[20];
    int count=0,choice;
    float r;

    program:
        cout<<"Enter radius: ";
        cin>>r;
        c[count]= new circle(r);
        c[count]->calculateArea();
        count++;

        cout<<"\nWant to add more circle? (1 for yes/0 for no)"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        if(choice!=1)
        {
            return 0;
        }
        else{
            cout<<endl;
            goto program;
        }
        cout<<"Anshkumar Darji - 24CE022"<<endl;
        return 0;
}