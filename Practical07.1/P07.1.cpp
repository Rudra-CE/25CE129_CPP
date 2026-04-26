#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Calculator
{
private:
    vector<string> results;

    void storeResult(string label, double value)
    {
        string entry = label + " = " + to_string(value);
        results.push_back(entry);
    }

public:
    int add(int a, int b)
    {
        int result = a + b;
        storeResult("add(" + to_string(a) + ", " + to_string(b) + ")", result);
        return result;
    }

    int add(int a, int b, int c)
    {
        int result = a + b + c;
        storeResult("add(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")", result);
        return result;
    }

    float add(float a, float b)
    {
        float result = a + b;
        storeResult("add(" + to_string(a) + ", " + to_string(b) + ")", result);
        return result;
    }

    double add(double a, double b)
    {
        double result = a + b;
        storeResult("add(" + to_string(a) + ", " + to_string(b) + ")", result);
        return result;
    }

    double add(int a, float b)
    {
        double result = a + b;
        storeResult("add(int " + to_string(a) + ", float " + to_string(b) + ")", result);
        return result;
    }

    double add(int a, double b)
    {
        double result = a + b;
        storeResult("add(int " + to_string(a) + ", double " + to_string(b) + ")", result);
        return result;
    }

    double add(float a, double b)
    {
        double result = a + b;
        storeResult("add(float " + to_string(a) + ", double " + to_string(b) + ")", result);
        return result;
    }

    void showResults()
    {
        cout << "\n============================================" << endl;
        cout << "       STORED CALCULATION RESULTS"          << endl;
        cout << "============================================" << endl;

        if (results.empty())
        {
            cout << "  [INFO] No results stored yet.\n";
            return;
        }

        for (int i = 0; i < (int)results.size(); i++)
        {
            cout << "  " << (i + 1) << ". " << results[i] << endl;
        }

        cout << "============================================" << endl;
        cout << "  Total Calculations: " << results.size()   << endl;
        cout << "============================================" << endl;
    }

    void clearResults()
    {
        results.clear();
        cout << "  [INFO] Result history cleared.\n";
    }
};

int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Calculator calc;

    cout << "\n============================================" << endl;
    cout << "     FUNCTION OVERLOADING CALCULATOR"       << endl;
    cout << "============================================" << endl;

    int choice;

    do
    {
        cout << "\n--------------------------------------------" << endl;
        cout << "  1.  Add two integers"                       << endl;
        cout << "  2.  Add three integers"                     << endl;
        cout << "  3.  Add two floats"                         << endl;
        cout << "  4.  Add two doubles"                        << endl;
        cout << "  5.  Add int + float"                        << endl;
        cout << "  6.  Add int + double"                       << endl;
        cout << "  7.  Add float + double"                     << endl;
        cout << "  8.  View all results"                       << endl;
        cout << "  9.  Clear results"                          << endl;
        cout << "  0.  Exit"                                   << endl;
        cout << "--------------------------------------------" << endl;
        cout << "  Enter choice: ";
        cin  >> choice;

        int    ia, ib, ic;
        float  fa, fb;
        double da, db;

        switch (choice)
        {
            case 1:
                cout << "  Enter two integers: ";
                cin  >> ia >> ib;
                cout << "  Result: " << calc.add(ia, ib) << endl;
                break;

            case 2:
                cout << "  Enter three integers: ";
                cin  >> ia >> ib >> ic;
                cout << "  Result: " << calc.add(ia, ib, ic) << endl;
                break;

            case 3:
                cout << "  Enter two floats: ";
                cin  >> fa >> fb;
                cout << "  Result: " << fixed << setprecision(4) << calc.add(fa, fb) << endl;
                break;

            case 4:
                cout << "  Enter two doubles: ";
                cin  >> da >> db;
                cout << "  Result: " << fixed << setprecision(6) << calc.add(da, db) << endl;
                break;

            case 5:
                cout << "  Enter int and float: ";
                cin  >> ia >> fa;
                cout << "  Result: " << fixed << setprecision(4) << calc.add(ia, fa) << endl;
                break;

            case 6:
                cout << "  Enter int and double: ";
                cin  >> ia >> da;
                cout << "  Result: " << fixed << setprecision(6) << calc.add(ia, da) << endl;
                break;

            case 7:
                cout << "  Enter float and double: ";
                cin  >> fa >> da;
                cout << "  Result: " << fixed << setprecision(6) << calc.add(fa, da) << endl;
                break;

            case 8:
                calc.showResults();
                break;

            case 9:
                calc.clearResults();
                break;

            case 0:
                cout << "\n  Exiting Calculator. Goodbye!\n";
                break;

            default:
                cout << "\n  [ERROR] Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
