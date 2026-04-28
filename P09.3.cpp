#include <iostream>
#include <vector>
#include <set>
#include <limits>
using namespace std;

int main() {
 cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    int n;

    while (true) {
        cout << "Enter number of elements: ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cout << "Invalid input! Enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> v[i];

            if (cin.fail()) {
                cout << "Invalid input! Enter an integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }

    cout << "\nOriginal list: ";
    for (int x : v) {
        cout << x << " ";
    }

    set<int> s(v.begin(), v.end());

    cout << "\nUnique elements using set: ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    vector<int> uniqueVec(s.begin(), s.end());

    cout << "\nConverted back to vector: ";
    for (int x : uniqueVec) {
        cout << x << " ";
    }

    return 0;
}
