#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
 cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    if (sentence.empty()) {
        cout << "Invalid input! Sentence cannot be empty.\n";
        return 0;
    }

    for (char &c : sentence) {
        if (ispunct(c)) c = ' ';
        else c = tolower(c);
    }

    map<string, int> freq;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";
    for (const auto &p : freq) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
