#include<iostream>
#include<string>
using namespace std;

class inventory
{
    int iid;
    string name;
    int price;
    int stock;

public:
    void add();
    void sold();
    void disply();
    int getid();

    inventory()
    {
        iid=0;
        name="null";
        price=0;
        stock=0;
    }

    inventory(int i,string n,int p,int s)
    {
        iid=i;
        name=n;
        price=p;
        stock=s;
    }
};

