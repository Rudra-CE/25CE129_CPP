#include<iostream>
#include<string>
using namespace std;

long long sumDigits(string n)
{
    long long sum = 0;

    for(int i = 0; i < n.length(); i++)
    {
        sum += n[i] - '0';
    }

    return sum;
}

int superDigit(long long n)
{
    if(n < 10)
        return n;

    long long sum = 0;

    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}

int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    string n;
    int k;

    cout<<"Enter number (string): ";
    cin>>n;

    cout<<"Enter k: ";
    cin>>k;

    long long initialSum = sumDigits(n);

    long long newNumber = initialSum * k;

    int result = superDigit(newNumber);

    cout<<"Super Digit = "<<result;

    return 0;
}
