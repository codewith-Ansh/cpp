#include<iostream>
using namespace std;

class Fahrenheit;

class Celsius {
public:
    float c;

    Celsius(float t=0){
        c=t;
    }

    Fahrenheit toFahrenheit();

    void show(){
        cout<<c<<"C"<<endl;
    }
};

class Fahrenheit {
public:
    float f;

    Fahrenheit(float t=0){
        f=t;
    }

    Celsius toCelsius(){
        return Celsius((f-32)*5/9);
    }

    void show(){
        cout<<f<<"F"<<endl;
    }
};

Fahrenheit Celsius::toFahrenheit(){
    return Fahrenheit((c*9/5)+32);
}

int main(){
    float x;
    int ch;

    while(1){
        cout<<"1.Celsius to Fahrenheit\n2.Fahrenheit to Celsius\n3.Exit\nEnter: ";
        cin>>ch;

        if(ch==1){
            cout<<"Celsius: ";
            cin>>x;
            Celsius c(x);
            Fahrenheit f=c.toFahrenheit();
            cout<<"Fahrenheit: ";
            f.show();
            cout<<endl;
        }
        else if(ch==2){
            cout<<"Fahrenheit: ";
            cin>>x;
            Fahrenheit f(x);
            Celsius c=f.toCelsius();
            cout<<"Celsius: ";
            c.show();
            cout<<endl;
        }
        else if(ch==3){
            break;
        }
        else{
            cout<<"Enter valid input"<<endl;
        }
    }

    cout<<"Anshkumar Darji-24CE022"<<endl;
    return 0;
}
