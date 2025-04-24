#include<iostream>
using namespace std;

class F;

class C {
public:
    float c;

    C(float t=0) {
        c=t;
    }

    F toF();

    void show() {
        cout<<c<<"C"<<endl;
    }
};

class F {
public:
    float f;

    F(float t=0) {
        f=t;
    }

    C toC() {
        return C((f-32)*5/9);
    }

    void show() {
        cout<<f<<"F"<<endl;
    }
};

F C::toF() {
    return F((c*9/5)+32);
}

int main() {
    float x;
    int ch;

    while(1) {
        cout<<"1.C to F\n2.F to C\n3.Exit\nEnter: ";
        cin>>ch;

        if(ch==1) {
            cout<<"C: ";
            cin>>x;
            C c(x);
            F f=c.toF();
            cout<<"F: ";
            f.show();
            cout<<endl;
        }
        else if(ch==2) {
            cout<<"F: ";
            cin>>x;
            F f(x);
            C c=f.toC();
            cout<<"C: ";
            c.show();
            cout<<endl;
        }
        else if(ch==3) {
            break;
        }
        else {
            cout<<"Enter valid input"<<endl;
        }
    }
    cout<<"Anshkumar Darji-24CE022"<<endl;
    return 0;
}
