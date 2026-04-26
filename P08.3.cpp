#include <iostream>
#include <string>
using namespace std;

string logs[100];
int logIndex = 0;

void addLog(string msg) {
    logs[logIndex++] = msg;
}

class BankAccount {
    double balance;
public:
    BankAccount(double b = 0) : balance(b) {}

    void deposit(double amount) {
        addLog("Enter deposit()");
        if (amount <= 0)
            throw "Invalid deposit amount";
        balance += amount;
        addLog("Exit deposit()");
    }

    void withdraw(double amount) {
        addLog("Enter withdraw()");
        if (amount > balance)
            throw "Insufficient balance";
        if (amount <= 0)
            throw "Invalid withdraw amount";
        balance -= amount;
        addLog("Exit withdraw()");
    }

    double getBalance() {
        return balance;
    }
};

void processWithdraw(BankAccount &acc, double amt) {
    addLog("Enter processWithdraw()");
    acc.withdraw(amt);
    addLog("Exit processWithdraw()");
}

void processDeposit(BankAccount &acc, double amt) {
    addLog("Enter processDeposit()");
    acc.deposit(amt);
    addLog("Exit processDeposit()");
}

int main() {
cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    BankAccount acc(1000);

    try {
        addLog("Start Transaction");
        processDeposit(acc, 500);
        processWithdraw(acc, 2000);
        addLog("End Transaction");
    }
    catch (const char* msg) {
        addLog("Exception caught in main()");
        cout << "Error: " << msg << endl;
    }

    cout << "\nTransaction Logs:\n";
    for (int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    cout << "\nFinal Balance: " << acc.getBalance() << endl;

    return 0;
}
