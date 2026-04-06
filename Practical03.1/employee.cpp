#include<iostream>
#include"employee.h"
using namespace std;

Employee::Employee()
{
    name = "";
    bsalary = 0;
    bonus = 1000;
    extraBonus = 0;
}

float Employee::totalSalary()
{
    return bsalary + bonus + extraBonus;
}

void Employee::input()
{
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Basic Salary: ";
    cin >> bsalary;

    cout << "Default Bonus = 1000\n";

    cout << "Enter Extra Bonus (0 if none): ";
    cin >> extraBonus;
}

void Employee::display()
{
    cout << "\nName: " << name;
    cout << "\nBasic Salary: " << bsalary;
    cout << "\nDefault Bonus: " << bonus;
    cout << "\nExtra Bonus: " << extraBonus;
    cout << "\nTotal Salary: " << totalSalary() << endl;
}
