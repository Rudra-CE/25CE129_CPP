#include<iostream>
using namespace std;
class bank_account
{
private :
    char account_holder_name[30];
    double account_number;
    float balance;

public :
    int search(double);
    void creataccount();
    void depositmoney();
    void withdrawmoney();
    void checkingbalanc();
};
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
    cout<<"enter accounr holder name :";
    cin>>account_holder_name;
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

int main()
{
    int ch,i;
    int t=0;
    double anumber;
    bank_account baccount[10];
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
option:

    cout<<"enter 1.  creat or add bank account."<<endl;
    cout<<"enter 2.  deposite money."<<endl;
    cout<<"enter 3.  withdraw money."<<endl;
    cout<<"enter 4.  checking bank balanc."<<endl;
    cout<<"enter 5.  exit."<<endl;
    cout<<"enter choice :";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {


    case 1:

        baccount[t].creataccount();
        t++;
        goto option;
    case 2:
        cout<<"enter bank account number :";
        cin>>anumber;

        for(i=0; i<t; i++)
        {
            if(baccount[i].search(anumber))
            {
                baccount[i].depositmoney();
                break;
            }
        }
        if(i==t)
        {
            cout<<"account not found.."<<endl;
        }

        goto option;
    case 3:
        cout<<"enter bank account number :";
        cin>>anumber;
        for(i=0; i<t; i++)
        {
            if(baccount[i].search(anumber))
            {
                baccount[i].withdrawmoney();
                break;
            }
        }
        if(i==t)
        {
            cout<<"account not found.."<<endl;
        }
        goto option;
    case 4:
        cout<<"enter bank account number :";
        cin>>anumber;

        for(i=0; i<t; i++)
        {
            if(baccount[i].search(anumber))
            {
                baccount[i].checkingbalanc();

            }

        }
        if(i==t)
        {
            cout<<"account not found.."<<endl;
        }
        goto option;
    case 5:
        cout<<"thank you ... visite again.."<<endl;
        return 0;
    default:
        cout<<"invalid choice .. enter your choice again.."<<endl;
        goto option;

    }




    return 0;
}
