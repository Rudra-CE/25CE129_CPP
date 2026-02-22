#include<iostream>
#include<string>
using namespace std;
class payment
{
private :
    string user_name;
    double wallet_id;
    float balance;

public :
    int search(double);
    void creatwallet();
    void loadmoney();
    void transfermoney();
    void displaywallet();
};
int payment::search(double wid)
{
    if(wid==wallet_id)
    {
        return 1;
    }
    else

        return 0;
}
void payment::creatwallet()
{
    cout<<"enter wallet user name :";
    cin.ignore();
    getline(cin,user_name);
    cout<<"enter wallet id :";
    cin>>wallet_id;
    cout<<"enter balance :";
    cin>>balance;
    cout<<endl;

}
void payment::transfermoney()
{
    double tammount=0;
    cout<<"enter ammount you want to transfer :";
    cin>>tammount;
    if(tammount>balance)
    {
        cout<<"not sufficient balance"<<endl;
        cout<<"enter choice again"<<endl;
    }
    else
    {
        cout<<"your transfer ammount is:"<<tammount<<endl;
        balance=balance-tammount;
        cout<<"final balance in your wallet is : "<<balance<<endl;
        cout<<endl;
    }
}
void payment::loadmoney()
{
    double lammount=0;
    cout<<"enter ammount you want to load :";
    cin>>lammount;
    cout<<"your load ammount is:"<<lammount<<endl;
    balance=balance+lammount;
    cout<<"final balance in your wallet is : "<<balance<<endl;
    cout<<endl;

}
void payment::displaywallet()
{
    cout<<"user name :"<<user_name<<endl;
    cout<<"wallet id :"<<wallet_id<<endl;
    cout<<"your balance is :"<<balance;
    cout<<endl;


}

int main()
{
    int ch,i;
    int t=0;
    double wid;
    payment w[10];
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
option:

    cout<<"enter 1.  creat or add wallet."<<endl;
    cout<<"enter 2.  load money."<<endl;
    cout<<"enter 3.  transfer money."<<endl;
    cout<<"enter 4.  disply wallet data."<<endl;
    cout<<"enter 5.  exit."<<endl;
    cout<<"enter choice :";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {


    case 1:

        w[t].creatwallet();
        t++;
        goto option;
    case 2:
        cout<<"enter wallet id :";
        cin>>wid;

        for(i=0; i<t; i++)
        {
            if(w[i].search(wid))
            {
                w[i].loadmoney();
                break;
            }
        }
        if(i==t)
        {
            cout<<"wallet not found.."<<endl;
        }

        goto option;
    case 3:
        cout<<"enter wallet id :";
        cin>>wid;

        for(i=0; i<t; i++)
        {
            if(w[i].search(wid))
            {
                w[i].transfermoney();
                break;
            }
        }
        if(i==t)
        {
            cout<<"wallet not found.."<<endl;
        }
        goto option;
    case 4:
        cout<<"enter wallet id :";
        cin>>wid;

        for(i=0; i<t; i++)
        {
            if(w[i].search(wid))
            {
                w[i].displaywallet();
break;
            }

        }
        if(i==t)
        {
            cout<<"wallet not found.."<<endl;
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

