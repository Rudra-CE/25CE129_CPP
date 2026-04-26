#include <iostream>
#include <vector>
using namespace std;

class Grading {
protected:
    float marks;
public:
    Grading(float m) : marks(m) {}
    virtual char computeGrade() = 0;
    virtual void display() = 0;
    virtual ~Grading() {}
};

class Undergraduate : public Grading {
    string name;
public:
    Undergraduate(string n, float m) : Grading(m), name(n) {}
    char computeGrade() {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 55) return 'C';
        else if (marks >= 40) return 'D';
        else return 'F';
    }
    void display() {
        cout << "Undergraduate: " << name << " Marks: " << marks << " Grade: " << computeGrade() << endl;
    }
};

class Postgraduate : public Grading {
    string name;
public:
    Postgraduate(string n, float m) : Grading(m), name(n) {}
    char computeGrade() {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else if (marks >= 50) return 'D';
        else return 'F';
    }
    void display() {
        cout << "Postgraduate: " << name << " Marks: " << marks << " Grade: " << computeGrade() << endl;
    }
};

int main() {
cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    vector<Grading*> students;
    int choice;
    string name;
    float marks;

    do {
        cout << "\n1. Add Undergraduate\n2. Add Postgraduate\n3. Display All\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name and marks: ";
            cin >> name >> marks;
            students.push_back(new Undergraduate(name, marks));
        } else if (choice == 2) {
            cout << "Enter name and marks: ";
            cin >> name >> marks;
            students.push_back(new Postgraduate(name, marks));
        } else if (choice == 3) {
            for (auto s : students)
                s->display();
        }

    } while (choice != 0);

    for (auto s : students)
        delete s;

    return 0;
}
