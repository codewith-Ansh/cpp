#include<iostream>
using namespace std;

class Rectangle{
private:
    float length,width;
public:
    void setDimensions(float l,float w){
        length=l;
        width=w;
    }
    float calculateArea(){
        return length*width;
    }
    float calculatePerimeter(){
        return 2*(length+width);
    }
};

int main(){
    Rectangle*rectangle;
    float l,w;
    int i=0;
    char choice;

    do{
        cout<<"Enter the length of rectangle "<<i+1<<": ";
        cin>>l;
        cout<<"Enter the width of rectangle "<<i+1<<": ";
        cin>>w;
        rectangle=new Rectangle();
        rectangle->setDimensions(l,w);
        cout<<"Area of rectangle "<<i+1<<": "<<rectangle->calculateArea()<<endl;
        cout<<"Perimeter of rectangle "<<i+1<<": "<<rectangle->calculatePerimeter()<<endl;

        cout<<"Do you want to add another rectangle?(y/n): ";
        cin>>choice;
        cout<<endl;
        i++;
    }while(choice=='y'||choice=='Y');

    delete rectangle;
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}