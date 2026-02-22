#include<iostream>
#include<string>
using namespace std;
class bank_account
{
private :
    string account_holder_name;
    double account_number;
    float balance;

public :
    int search(double);
    void creataccount();
    void depositmoney();
    void withdrawmoney();
    void checkingbalanc();
};
