#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isSpace(char c)
{
    return (c == ' ' || c == '\t' || c == '\r');
}

int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    string filename;
    cout << "Enter the filename to read: ";
    cin  >> filename;

    ifstream inFile(filename.c_str());

    if (!inFile)
    {
        cerr << "\n[ERROR] Cannot open file \"" << filename
             << "\". Please check the filename and try again.\n";
        return 1;
    }

    long totalChars = 0;
    long totalWords = 0;
    long totalLines = 0;

    string line;

    while (getline(inFile, line))
    {
        totalLines++;

        int lineLen = (int)line.size();
        totalChars += lineLen;

        bool inWord = false;

        for (int i = 0; i < lineLen; i++)
        {
            char c = line[i];

            if (!isSpace(c))
            {
                if (!inWord)
                {
                    totalWords++;
                    inWord = true;
                }
            }
            else
            {
                inWord = false;
            }
        }
    }

    inFile.close();

    cout << "  File Statistics for: " << filename << "\n";
    cout << "  Total Lines      : " << totalLines << "\n";
    cout << "  Total Words      : " << totalWords << "\n";
    cout << "  Total Characters : " << totalChars << "\n";

    return 0;
}

