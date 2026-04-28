#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

void display(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

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

    cout << "\nOriginal vector: ";
    display(v);

    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "Reversed using std::reverse(): ";
    display(v1);

    vector<int> v2 = v;

    vector<int>::iterator start = v2.begin();
    vector<int>::iterator end = v2.end() - 1;

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    cout << "Reversed using manual iterators: ";
    display(v2);

    return 0;
}
