#include<iostream>
#include<string>
#include<math.h>
#include"loan.h"
using namespace std;
void loan:: add()
{
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

}
void loan::display()
{
    cout<<" loan id :"<<lid<<endl;
    cout<<" Applicant name :"<<name<<endl;
    cout<<" Total loan amount :"<<total_loan_amount<<endl;
    cout<<" Annual interest rate :"<<annual_interest_rate<<endl;
cout<<" Loan tenure (months)  :"<<loan_tenure<<endl;
emi=(total_loan_amount*annual_interest_rate*pow(1.0+annual_interest_rate,loan_tenure))/(pow(1.0+annual_interest_rate,loan_tenure)-1.0);

cout<<"your monthley emi is :"<<emi<<endl;

}
