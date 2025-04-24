#include<iostream>
using namespace std;

class Complex {
    float real,imag;
public:
    Complex() {
        real=0;
        imag=0;
    }

    Complex(float r,float i) {
        real=r;
        imag=i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real+c.real,imag+c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real-c.real,imag-c.imag);
    }

    friend ostream& operator<<(ostream& out,const Complex& c) {
        out<<c.real;
        if(c.imag>=0) {
            out<<"+"<<c.imag<<"i";
        } else {
            out<<c.imag<<"i";
        }
        return out;
    }

    friend istream& operator>>(istream& in,Complex& c) {
        in>>c.real>>c.imag;
        return in;
    }
};

int main() {
    Complex c1,c2,sum,diff;
    cout<<"Enter first complex number (real and imaginary): ";
    cin>>c1;
    cout<<"Enter second complex number (real and imaginary): ";
    cin>>c2;

    sum=c1+c2;
    diff=c1-c2;

    cout<<"Sum: "<<sum<<endl;
    cout<<"Difference: "<<diff<<endl;
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}