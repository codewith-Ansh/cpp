#include <iostream>
using namespace std;

void add(int a, int b){
    cout<<"Sum: "<<a+b<<endl;
}

void add(float a, float b)
{
    cout<<"Sum: "<<a+b<<endl;
}

void add(int a, float b){
    cout<<"Sum: "<<a+b<<endl;
}

int main()
{
    int a,b;
    float c,d;
    cout<<"Enter two integers: ";
    cin>>a>>b;
    add(a,b);
    cout<<"Enter two float numbers: ";
    cin>>c>>d;
    add(c,d);

    cout<<"Enter one integer and one float: ";
    cin>>a>>c;
    add(a,c);

    cout<<"Anshkumar Darji - 24CE022"<<endl;  
    return 0;
}