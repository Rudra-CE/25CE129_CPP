#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main() {
 cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    map<string, vector<string>> directory;
    int choice;

    while (true) {
        cout << "\n1. Add Folder\n2. Add File\n3. Display Directory\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string folder;
            cout << "Enter folder name: ";
            getline(cin, folder);

            if (folder.empty()) {
                cout << "Invalid folder name!\n";
                continue;
            }

            if (directory.find(folder) != directory.end()) {
                cout << "Folder already exists!\n";
            } else {
                directory[folder] = vector<string>();
                cout << "Folder added.\n";
            }
        }
        else if (choice == 2) {
            if (directory.empty()) {
                cout << "No folders available!\n";
                continue;
            }

            string folder, file;
            cout << "Enter folder name: ";
            getline(cin, folder);

            if (directory.find(folder) == directory.end()) {
                cout << "Folder not found!\n";
                continue;
            }

            cout << "Enter file name: ";
            getline(cin, file);

            if (file.empty()) {
                cout << "Invalid file name!\n";
                continue;
            }

            directory[folder].push_back(file);
            cout << "File added.\n";
        }
        else if (choice == 3) {
            if (directory.empty()) {
                cout << "Directory is empty!\n";
                continue;
            }

            cout << "\nDirectory Contents:\n";
            for (map<string, vector<string>>::iterator it = directory.begin(); it != directory.end(); ++it) {
                cout << it->first << ":\n";
                if (it->second.empty()) {
                    cout << "  (No files)\n";
                } else {
                    for (vector<string>::iterator fit = it->second.begin(); fit != it->second.end(); ++fit) {
                        cout << "  - " << *fit << "\n";
                    }
                }
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
