#include <iostream>
using namespace std;

class Shape{
    public:
        virtual void CalculateArea()=0;
};

class Rectangle: public Shape{
    private:
        float Length,Breadth;
    public:
        Rectangle(float l, float b){
            Length=l;
            Breadth=b;
        }
        void CalculateArea(){
            cout<<"Area of rectangle is: "<<Length*Breadth<<endl;
        }
};

class Circle: public Shape{
    private:
        float Radius;
    public:
        Circle(float r){
            Radius=r;
        }
        void CalculateArea(){
            cout<<"Area of cicle is: "<<3.14*Radius*Radius<<endl;
        }
};

int main(){
    Shape *p;
    float l,b,r;
    int Choice;
    
    do{
        cout<<"Enter 1 for rectangle\nEnter 2 for circle\nEnter 0 to exit\nEnter your choice: ";
        cin>>Choice;

        switch(Choice){
            case 1:
                cout<<"Enter length and breadth of rectangle: ";
                cin>>l>>b;
                p = new Rectangle(l,b);
                p->CalculateArea();
                cout<<endl;
                delete p;
                break;
            case 2:
                cout<<"Enter radius of circle: ";
                cin>>r;
                p = new Circle(r);
                p->CalculateArea();
                cout<<endl;
                delete p;
                break;
            case 0:
                cout<<"\nThank you!"<<endl;
                cout<<"Anshkumar Darji - 24CE022"<<endl;
                break;
            default:
                cout<<"Enter valid choice!"<<endl;
                cout<<endl;
        }
    }while(Choice!=0);
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}