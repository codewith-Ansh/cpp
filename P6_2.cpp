#include<iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x=0, int y=0) {
        this->x = x;
        this->y = y;
    }

    Point* moveX(int dx) {
        x += dx;
        return this;
    }

    Point* moveY(int dy) {
        y += dy;
        return this;
    }

    void display() {
        cout<<"Point is at ("<<x<<","<<y<<")"<<endl;
    }
};

int main() {
    int startX, startY;
    cout<<"Enter starting X coordinate: ";
    cin>>startX;
    cout<<"Enter starting Y coordinate: ";
    cin>>startY;

    Point* p = new Point(startX, startY);
    p->display();
    
    int dx, dy;
    cout<<"Enter value to move in X direction: ";
    cin>>dx;
    cout<<"Enter value to move in Y direction: ";
    cin>>dy;

    
    p->moveX(dx)->moveY(dy);
    p->display();

    delete p;
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}