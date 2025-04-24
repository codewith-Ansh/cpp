#include<iostream>
using namespace std;

class Point {
    int x,y;
public:
    Point() {
        x=0;
        y=0;
    }

    Point(int a,int b) {
        x=a;
        y=b;
    }

    Point operator-() {
        return Point(-x,-y);
    }

    Point operator+(Point p) {
        return Point(x+p.x,y+p.y);
    }

    bool operator==(Point p) {
        return (x==p.x && y==p.y);
    }

    void input() {
        cout<<"Enter x and y: ";
        cin>>x>>y;
    }

    void display() {
        cout<<"("<<x<<","<<y<<")";
    }
};

int main() {
    Point p1,p2,p3,neg;
    p1.input();
    p2.input();

    cout<<"Point 1: ";
    p1.display();
    cout<<endl;

    cout<<"Point 2: ";
    p2.display();
    cout<<endl;

    p3=p1+p2;
    cout<<"Addition (p1+p2): ";
    p3.display();
    cout<<endl;

    neg=-p1;
    cout<<"Negation of p1: ";
    neg.display();
    cout<<endl;

    if(p1==p2) {
        cout<<"p1 and p2 are equal"<<endl;
    } else {
        cout<<"p1 and p2 are not equal"<<endl;
    }
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}