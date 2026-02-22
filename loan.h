#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class loan
{
    int lid;
    string name;
    float total_loan_amount;
    float annual_interest_rate;
    float loan_tenure;
    float emi;
public:

    void add();
    void display();
    loan()
    {
         lid=0;
        name="null";
        total_loan_amount=0;
        annual_interest_rate=0;
        loan_tenure=0;

    }
    loan(int i,string n, float lm,float ir,float lt)
    {
        lid=i;
        name=n;
        total_loan_amount=lm;
        annual_interest_rate=ir;
        loan_tenure=lt;
    }

};
