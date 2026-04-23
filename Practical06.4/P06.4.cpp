#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Account
{
protected:
    int    accNumber;
    float  balance;

public:
    Account(int no, float bal) : accNumber(no), balance(bal)
    {
        cout << "  [Account Created] Acc No: " << accNumber << endl;
    }

    ~Account()
    {
        cout << "  [Account Destroyed] Acc No: " << accNumber << endl;
    }

    void deposit(float amount)
    {
        if (amount <= 0)
        {
            cout << "  [ERROR] Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "  [Deposited] Rs " << amount << " | New Balance: Rs " << balance << endl;
    }

    float getBalance()
    {
        return balance;
    }

    int getAccNumber()
    {
        return accNumber;
    }

    virtual void display()
    {
        cout << "  Account No : " << accNumber << endl;
        cout << "  Balance    : Rs " << fixed << balance << endl;
    }

    virtual void withdraw(float amount) = 0;
};

class SavingsAccount : public Account
{
private:
    float            interestRate;
    stack<string>    history;

public:
    SavingsAccount(int no, float bal, float rate)
        : Account(no, bal), interestRate(rate)
    {
        cout << "  [Savings Account Ready]\n";
    }

    ~SavingsAccount()
    {
        cout << "  [Savings Account Closed]\n";
    }

    void deposit(float amount)
    {
        if (amount <= 0)
        {
            cout << "  [ERROR] Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        history.push("DEPOSIT Rs " + to_string((int)amount));
        cout << "  [Deposited] Rs " << amount << " | Balance: Rs " << balance << endl;
    }

    void withdraw(float amount)
    {
        if (amount <= 0)
        {
            cout << "  [ERROR] Withdrawal must be positive.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "  [ERROR] Insufficient balance.\n";
            return;
        }
        balance -= amount;
        history.push("WITHDRAW Rs " + to_string((int)amount));
        cout << "  [Withdrawn] Rs " << amount << " | Balance: Rs " << balance << endl;
    }

    void applyInterest()
    {
        float interest = balance * interestRate / 100;
        balance += interest;
        history.push("INTEREST Rs " + to_string((int)interest));
        cout << "  [Interest Applied] Rs " << interest << " | Balance: Rs " << balance << endl;
    }

    void undoLast()
    {
        if (history.empty())
        {
            cout << "  [INFO] No transactions to undo.\n";
            return;
        }
        cout << "  [UNDO] Last transaction removed: " << history.top() << endl;
        history.pop();
    }

    void showHistory()
    {
        if (history.empty())
        {
            cout << "  [INFO] No transaction history.\n";
            return;
        }

        stack<string> temp = history;
        cout << "\n  Transaction History (most recent first):" << endl;
        cout << "  ------------------------------------------" << endl;
        int i = 1;
        while (!temp.empty())
        {
            cout << "  " << i++ << ". " << temp.top() << endl;
            temp.pop();
        }
        cout << "  ------------------------------------------" << endl;
    }

    void display()
    {
        cout << "\n--------------------------------------------" << endl;
        cout << "  SAVINGS ACCOUNT DETAILS" << endl;
        cout << "--------------------------------------------" << endl;
        Account::display();
        cout << "  Interest   : " << interestRate << "%" << endl;
        cout << "--------------------------------------------" << endl;
    }
};

class CurrentAccount : public Account
{
private:
    float         overdraftLimit;
    stack<string> history;

public:
    CurrentAccount(int no, float bal, float limit)
        : Account(no, bal), overdraftLimit(limit)
    {
        cout << "  [Current Account Ready]\n";
    }

    ~CurrentAccount()
    {
        cout << "  [Current Account Closed]\n";
    }

    void deposit(float amount)
    {
        if (amount <= 0)
        {
            cout << "  [ERROR] Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        history.push("DEPOSIT Rs " + to_string((int)amount));
        cout << "  [Deposited] Rs " << amount << " | Balance: Rs " << balance << endl;
    }

    void withdraw(float amount)
    {
        if (amount <= 0)
        {
            cout << "  [ERROR] Withdrawal must be positive.\n";
            return;
        }
        if (amount > balance + overdraftLimit)
        {
            cout << "  [ERROR] Exceeds overdraft limit.\n";
            return;
        }
        balance -= amount;
        history.push("WITHDRAW Rs " + to_string((int)amount));
        cout << "  [Withdrawn] Rs " << amount << " | Balance: Rs " << balance << endl;
    }

    void undoLast()
    {
        if (history.empty())
        {
            cout << "  [INFO] No transactions to undo.\n";
            return;
        }
        cout << "  [UNDO] Last transaction removed: " << history.top() << endl;
        history.pop();
    }

    void showHistory()
    {
        if (history.empty())
        {
            cout << "  [INFO] No transaction history.\n";
            return;
        }

        stack<string> temp = history;
        cout << "\n  Transaction History (most recent first):" << endl;
        cout << "  ------------------------------------------" << endl;
        int i = 1;
        while (!temp.empty())
        {
            cout << "  " << i++ << ". " << temp.top() << endl;
            temp.pop();
        }
        cout << "  ------------------------------------------" << endl;
    }

    void display()
    {
        cout << "\n--------------------------------------------" << endl;
        cout << "  CURRENT ACCOUNT DETAILS" << endl;
        cout << "--------------------------------------------" << endl;
        Account::display();
        cout << "  Overdraft  : Rs " << overdraftLimit << endl;
        cout << "--------------------------------------------" << endl;
    }
};

int main()
{
      cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    cout << "\n============================================" << endl;
    cout << "        BANKING SYSTEM INITIALIZING"        << endl;
    cout << "============================================" << endl;

    SavingsAccount sa(1001, 50000.00, 4.5);
    CurrentAccount ca(2001, 30000.00, 10000.00);

    int choice;

    do
    {
        cout << "\n============================================" << endl;
        cout << "           BANKING SYSTEM MENU"             << endl;
        cout << "============================================" << endl;
        cout << "  --- Savings Account ---"                  << endl;
        cout << "  1. Deposit"                               << endl;
        cout << "  2. Withdraw"                              << endl;
        cout << "  3. Apply Interest"                        << endl;
        cout << "  4. Show Details"                          << endl;
        cout << "  5. Show History"                          << endl;
        cout << "  6. Undo Last Transaction"                 << endl;
        cout << "  --- Current Account ---"                  << endl;
        cout << "  7. Deposit"                               << endl;
        cout << "  8. Withdraw"                              << endl;
        cout << "  9. Show Details"                          << endl;
        cout << "  10. Show History"                         << endl;
        cout << "  11. Undo Last Transaction"                << endl;
        cout << "  0. Exit"                                  << endl;
        cout << "============================================" << endl;
        cout << "  Enter choice: ";
        cin  >> choice;

        float amount;

        switch (choice)
        {
            case 1:
                cout << "  Enter deposit amount: Rs ";
                cin  >> amount;
                sa.deposit(amount);
                break;

            case 2:
                cout << "  Enter withdrawal amount: Rs ";
                cin  >> amount;
                sa.withdraw(amount);
                break;

            case 3:
                sa.applyInterest();
                break;

            case 4:
                sa.display();
                break;

            case 5:
                sa.showHistory();
                break;

            case 6:
                sa.undoLast();
                break;

            case 7:
                cout << "  Enter deposit amount: Rs ";
                cin  >> amount;
                ca.deposit(amount);
                break;

            case 8:
                cout << "  Enter withdrawal amount: Rs ";
                cin  >> amount;
                ca.withdraw(amount);
                break;

            case 9:
                ca.display();
                break;

            case 10:
                ca.showHistory();
                break;

            case 11:
                ca.undoLast();
                break;

            case 0:
                cout << "\n  Exiting Banking System...\n";
                break;

            default:
                cout << "\n  [ERROR] Invalid choice.\n";
        }

    } while (choice != 0);

    cout << "\n============================================" << endl;
    cout << "        BANKING SYSTEM SHUTTING DOWN"       << endl;
    cout << "============================================" << endl;

    return 0;
}
