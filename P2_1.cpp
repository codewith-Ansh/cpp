#include<iostream>
using namespace std;

class rectangle{
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
    rectangle *r;
    float l,w;
    int i=0;
    char choice;

    do{
        cout<<"Enter the length of rectangle "<<i+1<<": ";
        cin>>l;
        cout<<"Enter the width of rectangle "<<i+1<<": ";
        cin>>w;
        r=new rectangle();
        r->setDimensions(l,w);
        cout<<"Area of rectangle "<<i+1<<": "<<r->calculateArea()<<endl;
        cout<<"Perimeter of rectangle "<<i+1<<": "<<r->calculatePerimeter()<<endl;

        cout<<"Do you want to add another rectangle?(y/n): ";
        cin>>choice;
        cout<<endl;
        i++;
    }while(choice=='y'||choice=='Y');

    delete r;
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}