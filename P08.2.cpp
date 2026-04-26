#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException {
public:
    void message() {
        cout << "Error: Negative number entered\n";
    }
};

int main() {
cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    double num;

    while (true) {
        cout << "Enter number: ";
        cin >> num;

        try {
            if (num < 0)
                throw NegativeNumberException();

            cout << "Square root: " << sqrt(num) << endl;
        }
        catch (NegativeNumberException e) {
            e.message();
        }
    }

    return 0;
}
