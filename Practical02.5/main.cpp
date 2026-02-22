#include<iostream>
#include<string>
#include<math.h>
#include"loan.h"
using namespace std;
int main ()
{
    int n;
    loan emi[100];
    cout<<"enter total number of customer you want to add in system :";
    cin>>n;
    int i;
    int ch;
    for(i=0; i<n; i++)
    {
        int lid;
        string name;
        float total_loan_amount;
        float annual_interest_rate;
        float loan_tenure;

        cout<<"enter loan id :";
        cin>>lid;

        cout<<"enter Applicant name :";
        cin>>name;

        cout<<"enter Total loan amount :";
        cin>>total_loan_amount;

        cout<<"enter Annual interest rate :";
        cin>>annual_interest_rate;

annual_interest_rate=annual_interest_rate/(1200);
        cout<<"enter Loan tenure (months)  :";
        cin>>loan_tenure;

        emi[i]=loan(lid,name,total_loan_amount,annual_interest_rate,loan_tenure);
    }
option:
    cout<<"enter 1. display loan deatail with monthley emi"<<endl;
    cout<<"enter 2. for again add loan details"<<endl;
    cout<<"enter 3. exit";
    cin>>ch;
    switch(ch)
    {
 case 1:
     for(i=0;i<n;i++)
     {

          emi[i].display();
     }
     break;
 case 2:
     for(i=n;i<100;i++)
     {
         int lid;
        string name;
        float total_loan_amount;
        float annual_interest_rate;
        float loan_tenure;

         cout<<"enter loan id :";
        cin>>lid;

        cout<<"enter Applicant name :";
        cin>>name;

        cout<<"enter Total loan amount :";
        cin>>total_loan_amount;

        cout<<"enter Annual interest rate :";
        cin>>annual_interest_rate;
        emi[n]=loan(lid,name,total_loan_amount,annual_interest_rate,loan_tenure);

annual_interest_rate=annual_interest_rate/(1200);

     }
     goto option;
 case 3:
    cout<<"thank you";
    break;
 default:
    cout<<"invalid choice ..\nenter choice again.."<<endl;
    }
    return 0;
}


