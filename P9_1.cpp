#include<iostream>
#include<stdexcept>
using namespace std;

int main() {
    double loanAmount,income,ratio;

    try {
        cout<<"Enter loan amount: ";
        cin>>loanAmount;

        if(cin.fail()) {
            throw invalid_argument("Invalid input for loan amount.");
        }

        cout<<"Enter annual income: ";
        cin>>income;

        if(cin.fail()) {
            throw invalid_argument("Invalid input for income.");
        }

        if(income==0) {
            throw runtime_error("Income cannot be zero.");
        }

        ratio=loanAmount/income;
        cout<<"Loan-to-Income Ratio: "<<ratio<<endl;
    }

    catch(const invalid_argument &e) {
        cout<<"Error: "<<e.what()<<endl;
    }

    catch(const runtime_error &e) {
        cout<<"Error: "<<e.what()<<endl;
    }

    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}
