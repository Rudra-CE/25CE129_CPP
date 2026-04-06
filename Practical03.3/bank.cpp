#include<iostream>
#include "bank.h"
using namespace std;

int bank::count = 0;

bank::bank()
{
    anumber = 0;
    ahname = "";
    abalance = 0;
}

bank::bank(int num, string name, float bal)
{
    anumber = num;
    ahname = name;
    abalance = bal;
    count++;
}

void bank::display()
{
    cout<<"\nName: "<<ahname;
    cout<<"\nAccount Number: "<<anumber;
    cout<<"\nBalance: "<<abalance<<endl;
}

int bank::getAccNo()
{
    return anumber;
}

float bank::getBalance()
{
    return abalance;
}

void bank::setBalance(float b)
{
    abalance = b;
}

void bank::update()
{
    cout<<"Enter new name: ";
    cin>>ahname;

    do
    {
        cout<<"Enter new balance (>=0): ";
        cin>>abalance;

        if(abalance < 0)
            cout<<"Invalid balance!\n";

    } while(abalance < 0);

    cout<<"Account updated successfully!";
}

void bank::displaycount()
{
    cout<<"\nTotal Accounts: "<<count<<endl;
}

