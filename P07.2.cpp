#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other)
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other)
    {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    bool operator==(const Complex& other)
    {
        return (real == other.real && imag == other.imag);
    }

    void display(string label = "")
    {
        if (label != "")
            cout << "  " << label << ": ";
        else
            cout << "  ";

        cout << fixed << setprecision(2) << real;

        if (imag >= 0)
            cout << " + " << imag << "i" << endl;
        else
            cout << " - " << (-imag) << "i" << endl;
    }

    float getReal() { return real; }
    float getImag() { return imag; }
};

void batchOperations(vector<Complex>& list)
{
    if (list.size() < 2)
    {
        cout << "  [INFO] Need at least 2 complex numbers for batch operations.\n";
        return;
    }

    cout << "\n--------------------------------------------" << endl;
    cout << "  BATCH OPERATIONS ON COLLECTION"            << endl;
    cout << "--------------------------------------------" << endl;

    Complex sumAll(0, 0);
    for (int i = 0; i < (int)list.size(); i++)
    {
        list[i].display("C" + to_string(i + 1));
        sumAll = sumAll + list[i];
    }

    cout << "--------------------------------------------" << endl;
    sumAll.display("Sum of All");
    cout << "--------------------------------------------" << endl;
}

int main()
{
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    vector<Complex> collection;

    int choice;

    do
    {
        cout << "\n============================================" << endl;
        cout << "     COMPLEX NUMBER CALCULATOR"             << endl;
        cout << "============================================" << endl;
        cout << "  1. Add two complex numbers"               << endl;
        cout << "  2. Subtract two complex numbers"          << endl;
        cout << "  3. Multiply two complex numbers"          << endl;
        cout << "  4. Compare two complex numbers"           << endl;
        cout << "  5. Add to collection"                     << endl;
        cout << "  6. Batch sum of collection"               << endl;
        cout << "  0. Exit"                                  << endl;
        cout << "============================================" << endl;
        cout << "  Enter choice: ";
        cin  >> choice;

        float r1, i1, r2, i2;

        switch (choice)
        {
            case 1:
                cout << "  Enter C1 (real imag): "; cin >> r1 >> i1;
                cout << "  Enter C2 (real imag): "; cin >> r2 >> i2;
                {
                    Complex c1(r1, i1), c2(r2, i2), result = c1 + c2;
                    cout << "\n--------------------------------------------" << endl;
                    c1.display("C1");
                    c2.display("C2");
                    cout << "  ---" << endl;
                    result.display("C1 + C2");
                    cout << "--------------------------------------------" << endl;
                }
                break;

            case 2:
                cout << "  Enter C1 (real imag): "; cin >> r1 >> i1;
                cout << "  Enter C2 (real imag): "; cin >> r2 >> i2;
                {
                    Complex c1(r1, i1), c2(r2, i2), result = c1 - c2;
                    cout << "\n--------------------------------------------" << endl;
                    c1.display("C1");
                    c2.display("C2");
                    cout << "  ---" << endl;
                    result.display("C1 - C2");
                    cout << "--------------------------------------------" << endl;
                }
                break;

            case 3:
                cout << "  Enter C1 (real imag): "; cin >> r1 >> i1;
                cout << "  Enter C2 (real imag): "; cin >> r2 >> i2;
                {
                    Complex c1(r1, i1), c2(r2, i2), result = c1 * c2;
                    cout << "\n--------------------------------------------" << endl;
                    c1.display("C1");
                    c2.display("C2");
                    cout << "  ---" << endl;
                    result.display("C1 * C2");
                    cout << "--------------------------------------------" << endl;
                }
                break;

            case 4:
                cout << "  Enter C1 (real imag): "; cin >> r1 >> i1;
                cout << "  Enter C2 (real imag): "; cin >> r2 >> i2;
                {
                    Complex c1(r1, i1), c2(r2, i2);
                    cout << "\n--------------------------------------------" << endl;
                    c1.display("C1");
                    c2.display("C2");
                    cout << "  ---" << endl;
                    if (c1 == c2)
                        cout << "  Result : C1 == C2 (Equal)" << endl;
                    else
                        cout << "  Result : C1 != C2 (Not Equal)" << endl;
                    cout << "--------------------------------------------" << endl;
                }
                break;

            case 5:
                cout << "  Enter complex number (real imag): "; cin >> r1 >> i1;
                collection.push_back(Complex(r1, i1));
                cout << "  [Added] Collection size: " << collection.size() << endl;
                break;

            case 6:
                batchOperations(collection);
                break;

            case 0:
                cout << "\n  Exiting. Goodbye!\n";
                break;

            default:
                cout << "\n  [ERROR] Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
