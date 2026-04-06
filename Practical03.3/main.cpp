#include<iostream>
#include "bank.h"
using namespace std;

int main()
{
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;

    int n;
    cout<<"Enter number of accounts: ";
    cin>>n;

    bank *acc = new bank[n];

    int i;

    for(i=0; i<n; i++)
    {
        string name;
        int num;
        float bal;

        cout<<"\nEnter details for account "<<i+1<<endl;

        cout<<"Enter Name: ";
        cin>>name;

        bool unique;
        do
        {
            unique = true;

            cout<<"Enter Account Number: ";
            cin>>num;

            for(int j=0; j<i; j++)
            {
                if(acc[j].getAccNo() == num)
                {
                    cout<<"Already exists! Try again.\n";
                    unique = false;
                    break;
                }
            }

        } while(!unique);

        do
        {
            cout<<"Enter Balance: ";
            cin>>bal;

            if(bal < 0)
                cout<<"Invalid balance!\n";

        } while(bal < 0);

        acc[i] = bank(num, name, bal);
    }

    int choice;

start:

    cout<<"\n\n===== MENU =====";
    cout<<"\n1. Display All Accounts";
    cout<<"\n2. Transfer Money";
    cout<<"\n3. Total Accounts";
    cout<<"\n4. Add New Account";
    cout<<"\n5. Update Account";
    cout<<"\n6. Exit";
    cout<<"\nEnter choice: ";
    cin>>choice;

    if(choice == 1)
    {
        for(i=0; i<n; i++)
            acc[i].display();

        goto start;
    }

    else if(choice == 2)
    {
        int from, to;
        float amt;

        cout<<"Enter sender account number: ";
        cin>>from;

        cout<<"Enter receiver account number: ";
        cin>>to;

        cout<<"Enter amount: ";
        cin>>amt;

        int f=-1, t=-1;

        for(i=0; i<n; i++)
        {
            if(acc[i].getAccNo() == from)
                f = i;
            if(acc[i].getAccNo() == to)
                t = i;
        }

        if(f==-1 || t==-1)
        {
            cout<<"Invalid account!";
        }
        else if(amt <= 0)
        {
            cout<<"Invalid amount!";
        }
        else if(acc[f].getBalance() < amt)
        {
            cout<<"Insufficient balance!";
        }
        else
        {
            acc[f].setBalance(acc[f].getBalance() - amt);
            acc[t].setBalance(acc[t].getBalance() + amt);

            cout<<"Transfer successful!";
        }

        goto start;
    }

    else if(choice == 3)
    {
        bank::displaycount();
        goto start;
    }

    else if(choice == 4)
    {
        bank *temp = new bank[n+1];

        for(i=0; i<n; i++)
            temp[i] = acc[i];

        string name;
        int num;
        float bal;

        cout<<"\nEnter details for new account:\n";

        cout<<"Enter Name: ";
        cin>>name;

        bool unique;
        do
        {
            unique = true;

            cout<<"Enter Account Number: ";
            cin>>num;

            for(int j=0; j<n; j++)
            {
                if(acc[j].getAccNo() == num)
                {
                    cout<<"Already exists!\n";
                    unique = false;
                    break;
                }
            }

        } while(!unique);

        do
        {
            cout<<"Enter Balance: ";
            cin>>bal;

            if(bal < 0)
                cout<<"Invalid balance!\n";

        } while(bal < 0);

        temp[n] = bank(num, name, bal);

        delete[] acc;
        acc = temp;
        n++;

        cout<<"Account added successfully!";
        goto start;
    }

    else if(choice == 5)
    {
        int num;
        cout<<"Enter account number to update: ";
        cin>>num;

        int index = -1;

        for(i=0; i<n; i++)
        {
            if(acc[i].getAccNo() == num)
                index = i;
        }

        if(index == -1)
        {
            cout<<"Account not found!";
        }
        else
        {
            acc[index].update();
        }

        goto start;
    }

    else if(choice == 6)
    {
        delete[] acc;
        return 0;
    }

    else
    {
        cout<<"Invalid choice!";
        goto start;
    }
}

