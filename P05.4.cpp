#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

ostream& currency(ostream& os)
{
    os << "Rs ";
    return os;
}

struct Student
{
    string name;
    int rollNo;
    float marks;
    float fees;
};

int main()
{
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Student students[] =
    {
        {"Rudra Patel",   101, 88.50, 45000.00},
        {"Aanya Shah",    102, 76.25, 42000.00},
        {"Mihir Desai",   103, 91.00, 47500.00},
        {"Pooja Mehta",   104, 63.75, 40000.00},
        {"Arjun Trivedi", 105, 55.50, 38000.00}
    };

    int total = 5;

    cout << endl;
    cout << setfill('=') << setw(70) << "" << endl;
    cout << setfill(' ');
    cout << setw(28) << "" << "STUDENT REPORT CARD" << endl;
    cout << setfill('=') << setw(70) << "" << endl;
    cout << setfill(' ');

    cout << left
         << setw(5)  << "No"
         << setw(20) << "Student Name"
         << setw(12) << "Roll No"
         << setw(12) << "Marks (%)"
         << setw(15) << "Fees"
         << endl;

    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < total; i++)
    {
        cout << left
             << setw(5)  << (i + 1)
             << setw(20) << students[i].name
             << setw(12) << students[i].rollNo
             << setw(12) << fixed << setprecision(2) << students[i].marks
             << currency << setw(10) << fixed << setprecision(2) << students[i].fees
             << endl;
    }

    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' ');

    float total_marks = 0;
    float total_fees  = 0;

    for (int i = 0; i < total; i++)
    {
        total_marks += students[i].marks;
        total_fees  += students[i].fees;
    }

    float average = total_marks / total;

    cout << left
         << setw(5)  << ""
         << setw(20) << "Class Average"
         << setw(12) << ""
         << setw(12) << fixed << setprecision(2) << average
         << endl;

    cout << left
         << setw(5)  << ""
         << setw(20) << "Total Fees Collected"
         << setw(12) << ""
         << setw(12) << ""
         << currency << fixed << setprecision(2) << total_fees
         << endl;

    cout << setfill('=') << setw(70) << "" << endl;
    cout << setfill(' ');

    cout << endl;
    cout << "  Grade Summary:" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < total; i++)
    {
        string grade;

        if      (students[i].marks >= 90) grade = "A+";
        else if (students[i].marks >= 80) grade = "A";
        else if (students[i].marks >= 70) grade = "B";
        else if (students[i].marks >= 60) grade = "C";
        else if (students[i].marks >= 50) grade = "D";
        else                              grade = "F";

        cout << "  "
             << left  << setw(20) << students[i].name
             << right << setw(8)  << fixed << setprecision(2) << students[i].marks << "%"
             << setw(6) << grade
             << endl;
    }

    cout << setfill('-') << setw(40) << "" << endl;
    cout << setfill(' ');

    return 0;
}
