#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Fuel
{
protected:
    string fuelType;

public:
    Fuel(string f) : fuelType(f) {}

    void displayFuel()
    {
        cout << "  Fuel Type  : " << fuelType << endl;
    }
};

class Brand
{
protected:
    string brandName;

public:
    Brand(string b) : brandName(b) {}

    void displayBrand()
    {
        cout << "  Brand      : " << brandName << endl;
    }
};

class Car : public Fuel, public Brand
{
private:
    string model;
    int    year;
    float  price;

public:
    Car(string f, string b, string m, int y, float p)
        : Fuel(f), Brand(b), model(m), year(y), price(p) {}

    void display()
    {
        cout << "\n--------------------------------------------" << endl;
        cout << "  CAR DETAILS" << endl;
        cout << "--------------------------------------------" << endl;
        displayBrand();
        cout << "  Model      : " << model << endl;
        cout << "  Year       : " << year  << endl;
        displayFuel();
        cout << "  Price      : Rs " << fixed << price << endl;
        cout << "--------------------------------------------" << endl;
    }

    string getModel()
    {
        return model;
    }
};

void methodOne(queue<Car> serviceQueue)
{
    cout << "\n============================================" << endl;
    cout << "   SERVICE QUEUE (Queue - FIFO Order)"      << endl;
    cout << "============================================" << endl;

    int position = 1;

    while (!serviceQueue.empty())
    {
        cout << "\n  Queue Position: " << position++ << endl;
        serviceQueue.front().display();
        serviceQueue.pop();
    }
}

void methodTwo(Car cars[], int size)
{
    cout << "\n============================================" << endl;
    cout << "   ALL CARS (Static Array)"                  << endl;
    cout << "============================================" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "\n  Record " << (i + 1) << ":" << endl;
        cars[i].display();
    }
}

int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    Car c1("Petrol",   "Toyota",  "Innova Crysta", 2022, 1850000.00);
    Car c2("Diesel",   "Mahindra","Scorpio N",      2023, 1650000.00);
    Car c3("Electric", "Tata",    "Nexon EV",       2023, 1450000.00);
    Car c4("Petrol",   "Honda",   "City",           2021, 1200000.00);
    Car c5("Diesel",   "Hyundai", "Creta",          2022, 1550000.00);

    queue<Car> serviceQueue;
    serviceQueue.push(c1);
    serviceQueue.push(c2);
    serviceQueue.push(c3);
    serviceQueue.push(c4);
    serviceQueue.push(c5);

    Car cars[] = {c1, c2, c3, c4, c5};
    int size = 5;

    int choice;

    do
    {
        cout << "\n============================================" << endl;
        cout << "    VEHICLE MANAGEMENT SYSTEM"               << endl;
        cout << "============================================" << endl;
        cout << "  1. View Service Queue (Queue Method)"      << endl;
        cout << "  2. View All Cars (Static Array Method)"    << endl;
        cout << "  3. Exit"                                   << endl;
        cout << "============================================" << endl;
        cout << "  Enter choice: ";
        cin  >> choice;

        switch (choice)
        {
            case 1: methodOne(serviceQueue);    break;
            case 2: methodTwo(cars, size);      break;
            case 3: cout << "\n  Exiting system. Goodbye!\n"; break;
            default: cout << "\n  [ERROR] Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
