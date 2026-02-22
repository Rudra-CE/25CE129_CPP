#include<iostream>
#include<string>
#include "bank_account.h"

using namespace std;

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
    cout<<"enter 4.  checking bank balance."<<endl;
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
break;
            }

        }
        if(i==t)
        {
            cout<<"account not found.."<<endl;
        }
        goto option;
    case 5:
        cout<<"thank you ... visite again.."<<endl;
        break;
    default:
        cout<<"invalid choice .. enter your choice again.."<<endl;
        goto option;

    }




    return 0;
}
