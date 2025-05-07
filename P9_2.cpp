#include<iostream>
using namespace std;

class BankAccount {
private:
    int balance;
    string transactions[100];
    int transactionCount;

public:
    BankAccount() {
        balance = 0;
        transactionCount = 0;
    }

    void deposit(int amount) {
        try {
            if (amount <= 0) {
                throw 1;
            }
            balance += amount;
            if (transactionCount < 100) {
                transactions[transactionCount++] = "Deposited: " + intToString(amount);
            }
            cout << "Deposit successful. Current balance: " << balance << endl;
        } catch (...) {
            logError("deposit");
            cout << "Error: Deposit amount must be greater than 0" << endl;
        }
    }

    void withdraw(int amount) {
        try {
            if (amount <= 0) {
                throw 1;
            }
            if (amount > balance) {
                throw 2;
            }
            balance -= amount;
            if (transactionCount < 100) {
                transactions[transactionCount++] = "Withdrew: " + intToString(amount);
            }
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        } catch (int e) {
            logError("withdraw");
            if (e == 1)
                cout << "Error: Withdrawal amount must be greater than 0" << endl;
            else
                cout << "Error: Insufficient balance" << endl;
        }
    }

    void showHistory() {
        cout << "Transaction History:" << endl;
        for (int i = 0; i < transactionCount; i++) {
            cout << transactions[i] << endl;
        }
    }

    void logError(string functionName) {
        if (transactionCount < 100) {
            transactions[transactionCount++] = "Error occurred in: " + functionName;
        }
    }

    string intToString(int num) {
        string result = "";
        bool isNegative = false;

        if (num == 0) {
            return "0";
        }

        if (num < 0) {
            isNegative = true;
            num = -num;
        }

        while (num > 0) {
            result = char((num % 10) + '0') + result;
            num /= 10;
        }

        if (isNegative) {
            result = "-" + result;
        }

        return result;
    }
};

int main() {
    BankAccount account;
    int choice, amount;

    while (true) {
        cout << "1. Deposit\n2. Withdraw\n3. Show History\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.showHistory();
                break;
            case 4:
                cout << "Anshkumar Darji - 24CE022" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}