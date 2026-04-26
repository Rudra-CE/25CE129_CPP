#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    float temp;
public:
    Celsius(float t = 0) : temp(t) {}
    float getTemp() const { return temp; }
    operator Fahrenheit();
    bool operator==(const Celsius& other) {
        return temp == other.temp;
    }
};

class Fahrenheit {
private:
    float temp;
public:
    Fahrenheit(float t = 0) : temp(t) {}
    float getTemp() const { return temp; }
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }
    bool operator==(const Fahrenheit& other) {
        return temp == other.temp;
    }
    friend class Celsius;
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {
      cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;
    cout << "25 Celsius = " << f1.getTemp() << " Fahrenheit\n";

    Celsius c2;
    c2 = f1;
    cout << "Back to Celsius = " << c2.getTemp() << endl;

    Celsius c3(25);
    if (c1 == c3)
        cout << "Temperatures are equal (Celsius)\n";

    queue<Fahrenheit> tempQueue;

    tempQueue.push(c1);
    tempQueue.push(Celsius(30));
    tempQueue.push(Celsius(35));

    cout << "\nQueue contents (Fahrenheit):\n";
    while (!tempQueue.empty()) {
        cout << tempQueue.front().getTemp() << endl;
        tempQueue.pop();
    }

    Fahrenheit arr[3];
    arr[0] = Celsius(10);
    arr[1] = Celsius(20);
    arr[2] = Celsius(30);

    cout << "\nArray contents (Fahrenheit):\n";
    for (int i = 0; i < 3; i++) {
        cout << arr[i].getTemp() << endl;
    }

    return 0;
}
