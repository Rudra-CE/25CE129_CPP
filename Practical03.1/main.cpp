#include<iostream>
#include"employee.h"
using namespace std;

void addEmployee(Employee *&emp, int &n)
{
    Employee *temp = new Employee[n + 1];

    for(int i = 0; i < n; i++)
    {
        temp[i] = emp[i];
    }

    cout << "\nEnter details of new employee:\n";
    temp[n].input();

    delete[] emp;
    emp = temp;

    n++;
}

int main()
{
    Employee *emp = NULL;
    int n = 0;
    int choice, i;

    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGINEERING\n"<<endl;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Employees\n";
        cout << "2. Display Employees\n";
        cout << "3. Add New Employee\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "Enter number of employees: ";
                cin >> n;

                emp = new Employee[n];

                for(i = 0; i < n; i++)
                {
                    cout << "\nEmployee " << i+1 << endl;
                    emp[i].input();
                }
                break;
            }

            case 2:
            {
                for(i = 0; i < n; i++)
                {
                    emp[i].display();
                }
                break;
            }

            case 3:
            {
                addEmployee(emp, n);
                break;
            }

            case 4:
            {
                cout << "Exiting...\n";
                break;
            }

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    delete[] emp;

    return 0;
}
