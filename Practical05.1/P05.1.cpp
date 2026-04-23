#include <iostream>
#include <string>
using namespace std;

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    return s;
}

int main() {
      cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    string para;
    cout << "Enter paragraph: ";
    getline(cin, para);

    string words[1000];
    int count[1000] = {0};
    int n = 0;

    string temp = "";

    for (int i = 0; i <= para.length(); i++) {
        if (para[i] == ' ' || para[i] == '\0') {
            if (temp != "") {
                temp = toLower(temp);

                int found = -1;
                for (int j = 0; j < n; j++) {
                    if (words[j] == temp) {
                        found = j;
                        break;
                    }
                }

                if (found == -1) {
                    words[n] = temp;
                    count[n] = 1;
                    n++;
                } else {
                    count[found]++;
                }

                temp = "";
            }
        } else {
            temp += para[i];
        }
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < n; i++) {
        cout << words[i] << " : " << count[i] << endl;
    }

    return 0;
}
