#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class BankAccount{
    string accHoldername;
    int accNumber;
    float balance;

    public:
        BankAccount()
        {
            accHoldername='\0';
            accNumber=0;
            balance=0.0;
        }
        BankAccount(string name,int number,float balanceAmount)
        {
            accHoldername=name;
            accNumber=number;
            balance=balanceAmount;
        }

        void deposit(float amount)
        {
            balance+=amount;
        }
        void withdraw(float amount)
        {
            if(balance>=amount){
            balance -= amount;
            }
            else
            {
                cout<<"Not enough balance!"<<endl;
            }
        }
        void displayAccDetails()
        {
            cout<<"Account Holder name: "<<accHoldername<<endl;
            cout<<"Accout number: "<<accNumber<<endl;
            cout<<"Current Balance: "<<balance<<endl;
        }
};

int main()
{
    string name;
    int number,choice;
    float balanceAmount,amount;

    BankAccount B;

    cout<<"Enter account holder name: ";
    getline(cin,name);
    cout<<"Enter account number: ";
    cin>>number;
    cout<<"Enter account balance: ";
    cin>>balanceAmount;

    B = BankAccount(name,number,balanceAmount);

    cout<<"\nENTER 1 FOR DEPOSIT!\nENTER 2 FOR WITHDRAW\nENTER 3 FOR DISPLAY DETAILS!\nENTER 0 FOR EXIT!\n";
    do{
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter amount to deposit: ";
                cin>>amount;
                B.deposit(amount);
                break;
            case 2:
                cout<<"Enter amount to withdraw: ";
                cin>>amount;
                B.withdraw(amount);
                break;
            case 3:
                B.displayAccDetails();
                break;
            case 0:
                cout<<"Thank you!"<<endl;
                break;
            default:
                cout<<"Choice is invalid!"<<endl;
        }
    }while(choice!=0);
    cout<<"Anshkumar Darji - 24CE022"<<endl;
}