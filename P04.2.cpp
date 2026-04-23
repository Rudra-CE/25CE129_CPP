#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

void updatePoint(Point *p, int dx, int dy) {
    p->move(dx, dy);
}

int main() {
  cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Point p(1, 2);

    cout << "Original Point: ";
    p.display();

    p.move(2, 3).move(-1, 4);

    cout << "After Chain Moves: ";
    p.display();

    updatePoint(&p, 5, -2);

    cout << "After Pointer Update: ";
    p.display();

    return 0;
}
