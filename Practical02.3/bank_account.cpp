#include "bank_account.h"
int bank_account::search(double anumber)
{
    if(anumber==account_number)
    {
        return 1;
    }
    else

        return 0;
}
void bank_account::creataccount()
{
    cout<<"enter account holder name :";
    cin.ignore();
    getline(cin,account_holder_name);
    cout<<"enter account number :";
    cin>>account_number;
    cout<<"enter balance :";
    cin>>balance;
    cout<<endl;

}
void bank_account::withdrawmoney()
{
    double wammount=0;
    cout<<"enter ammount you want to withdraw :";
    cin>>wammount;
    if(wammount>balance)
    {
        cout<<"not sufficient balance"<<endl;
        cout<<"enter choice again"<<endl;
    }
    else
    {
        cout<<"your withdrawl ammount is:"<<wammount<<endl;
        balance=balance-wammount;
        cout<<"final balance in your bank account is : "<<balance<<endl;
        cout<<endl;
    }
}
void bank_account::depositmoney()
{
    double dammount=0;
    cout<<"enter ammount you want to deposite :";
    cin>>dammount;
    cout<<"your deposit ammount is:"<<dammount<<endl;
    balance=balance+dammount;
    cout<<"final balance in your bank account is : "<<balance<<endl;
    cout<<endl;

}
void bank_account::checkingbalanc()
{
    cout<<"your balance is :"<<balance;
    cout<<endl;


}

