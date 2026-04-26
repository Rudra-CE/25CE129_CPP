#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
    int* data;
public:
    Derived() {
        data = new int[5];
        cout << "Derived Constructor\n";
    }
    ~Derived() {
        delete[] data;
        cout << "Derived Destructor\n";
    }
};

int main() {
cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}
