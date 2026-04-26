#include <iostream>
using namespace std;

class Shape {
public:
    virtual float Area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float Area() {
        return length * width;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}
    float Area() {
        return 3.1416 * radius * radius;
    }
};

int main() {
 cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Shape* dynamicShapes[100];
    int n = 0;

    dynamicShapes[n++] = new Rectangle(5, 4);
    dynamicShapes[n++] = new Circle(3);
    dynamicShapes[n++] = new Rectangle(2, 6);

    cout << "Dynamic Storage:\n";
    for (int i = 0; i < n; i++) {
        cout << dynamicShapes[i]->Area() << endl;
    }

    for (int i = 0; i < n; i++) {
        delete dynamicShapes[i];
    }

    Shape* staticShapes[3];
    staticShapes[0] = new Rectangle(3, 3);
    staticShapes[1] = new Circle(2);
    staticShapes[2] = new Rectangle(7, 2);

    cout << "\nStatic Storage:\n";
    for (int i = 0; i < 3; i++) {
        cout << staticShapes[i]->Area() << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete staticShapes[i];
    }

    return 0;
}
