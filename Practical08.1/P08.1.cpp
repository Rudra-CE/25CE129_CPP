#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;

    try {
        cout << "Enter numerator: ";
        if (!(cin >> a))
            throw "Invalid input";

        cout << "Enter denominator: ";
        if (!(cin >> b))
            throw "Invalid input";

        if (b == 0)
            throw "Division by zero";

        cout << "Result: " << a / b << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
