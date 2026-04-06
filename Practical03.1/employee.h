#include<string>
using namespace std;

class Employee
{
private:
    string name;
    float bsalary;
    float bonus;
    float extraBonus;

public:
    Employee();

    float totalSalary();

    void input();
    void display();
};
