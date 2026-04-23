#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string FILENAME = "inventory.txt";

void addItem()
{
    string name;
    int quantity;
    float price;

    cout << "\nEnter Item Name     : ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter Quantity      : ";
    cin >> quantity;
    cout << "Enter Price         : ";
    cin >> price;

    ofstream outFile(FILENAME.c_str(), ios::app);

    if (!outFile)
    {
        cerr << "[ERROR] Could not open inventory file for writing.\n";
        return;
    }

    outFile << name << "\n" << quantity << "\n" << price << "\n";
    outFile.close();

    cout << "\n[SUCCESS] Item \"" << name << "\" added to inventory.\n";
}

void viewAllItems()
{
    ifstream inFile(FILENAME.c_str());

    if (!inFile)
    {
        cout << "\n[INFO] Inventory file not found or is empty.\n";
        return;
    }

    string name;
    int quantity;
    float price;
    int count = 0;

    cout << "\n============================================================\n";
    cout << left << setw(20) << "Item Name"
         << setw(12) << "Quantity"
         << setw(10) << "Price (Rs)" << "\n";
    cout << "============================================================\n";

    while (getline(inFile, name))
    {
        inFile >> quantity >> price;
        inFile.ignore();

        cout << left << setw(20) << name
             << setw(12) << quantity
             << setw(10) << fixed << setprecision(2) << price << "\n";
        count++;
    }

    inFile.close();

    if (count == 0)
        cout << "[INFO] No items found in inventory.\n";

    cout << "============================================================\n";
    cout << "Total Items: " << count << "\n";
}

void searchItem()
{
    string target;
    cout << "\nEnter Item Name to Search: ";
    cin >> ws;
    getline(cin, target);

    ifstream inFile(FILENAME.c_str());

    if (!inFile)
    {
        cout << "[INFO] Inventory file not found.\n";
        return;
    }

    string name;
    int quantity;
    float price;
    bool found = false;

    while (getline(inFile, name))
    {
        inFile >> quantity >> price;
        inFile.ignore();

        if (name == target)
        {
            cout << "\n============================================================\n";
            cout << "  Item Found!\n";
            cout << "============================================================\n";
            cout << "  Name     : " << name     << "\n";
            cout << "  Quantity : " << quantity << "\n";
            cout << "  Price    : Rs " << fixed << setprecision(2) << price << "\n";
            cout << "============================================================\n";
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found)
        cout << "\n[INFO] Item \"" << target << "\" not found in inventory.\n";
}

int main()
{
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    int choice;

    do
    {
        cout << "\n============================================================\n";
        cout << "           INVENTORY MANAGEMENT SYSTEM                     \n";
        cout << "============================================================\n";
        cout << "  1. Add Item\n";
        cout << "  2. View All Items\n";
        cout << "  3. Search Item by Name\n";
        cout << "  4. Exit\n";
        cout << "============================================================\n";
        cout << "  Enter your choice: ";
        cin  >> choice;

        switch (choice)
        {
            case 1: addItem();      break;
            case 2: viewAllItems(); break;
            case 3: searchItem();   break;
            case 4: cout << "\nExiting... Goodbye!\n"; break;
            default: cout << "\n[ERROR] Invalid choice. Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}
