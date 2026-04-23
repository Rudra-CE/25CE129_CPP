#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person
{
protected:
    string name;
    int    age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void display()
    {
        cout << "  Name       : " << name << endl;
        cout << "  Age        : " << age  << endl;
    }
};

class Employee : public Person
{
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a), empID(id) {}

    void display()
    {
        Person::display();
        cout << "  Employee ID: " << empID << endl;
    }

    int getID()
    {
        return empID;
    }
};

class Manager : public Employee
{
private:
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id), department(dept) {}

    void display()
    {
        cout << "\n--------------------------------------------" << endl;
        cout << "  MANAGER PROFILE" << endl;
        cout << "--------------------------------------------" << endl;
        Employee::display();
        cout << "  Department : " << department << endl;
        cout << "--------------------------------------------" << endl;
    }

    string getDepartment()
    {
        return department;
    }
};

void strategyOne(map<int, Manager*>& directory)
{
    int searchID;
    cout << "\n  Enter Employee ID to search: ";
    cin  >> searchID;

    map<int, Manager*>::iterator it = directory.find(searchID);

    if (it != directory.end())
    {
        cout << "\n  [FOUND] Manager details:" << endl;
        it->second->display();
    }
    else
    {
        cout << "\n  [NOT FOUND] No manager with ID " << searchID << endl;
    }
}

void strategyTwo(Manager managers[], int size)
{
    cout << "\n============================================" << endl;
    cout << "   ALL MANAGERS (Static Array)"              << endl;
    cout << "============================================" << endl;

    for (int i = 0; i < size; i++)
    {
        managers[i].display();
    }
}

int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Manager m1("Rudra Patel",   35, 101, "Engineering");
    Manager m2("Aanya Shah",    42, 102, "Human Resources");
    Manager m3("Mihir Desai",   38, 103, "Finance");
    Manager m4("Pooja Mehta",   45, 104, "Marketing");
    Manager m5("Arjun Trivedi", 50, 105, "Operations");

    map<int, Manager*> directory;
    directory[m1.getID()] = &m1;
    directory[m2.getID()] = &m2;
    directory[m3.getID()] = &m3;
    directory[m4.getID()] = &m4;
    directory[m5.getID()] = &m5;

    Manager managers[] = {m1, m2, m3, m4, m5};
    int size = 5;

    int choice;

    do
    {
        cout << "\n============================================" << endl;
        cout << "    ORGANIZATION HIERARCHY SYSTEM"           << endl;
        cout << "============================================" << endl;
        cout << "  1. Search Manager by Employee ID (Map)"    << endl;
        cout << "  2. View All Managers (Static Array)"       << endl;
        cout << "  3. Exit"                                   << endl;
        cout << "============================================" << endl;
        cout << "  Enter choice: ";
        cin  >> choice;

        switch (choice)
        {
            case 1: strategyOne(directory);        break;
            case 2: strategyTwo(managers, size);   break;
            case 3: cout << "\n  Exiting system. Goodbye!\n"; break;
            default: cout << "\n  [ERROR] Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
