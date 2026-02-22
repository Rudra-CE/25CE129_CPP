#include<iostream>
#include<string>
#include"inventory.h"

int inventory::getid()
{

   return iid;
}

void inventory::add()
{
    int s=0;
    cout<<"enter stock you want to add :";
    cin>>s;
    stock+=s;
    cout<<"stock updated ..."<<endl;
}

void inventory::sold()
{
    int s=0;
    cout<<"enter number of item you sell :";
    cin>>s;

    if(s > stock)
    {
        cout<<"not enough stock available!"<<endl;
    }
    else
    {
        stock-=s;
        cout<<"stock updated ..."<<endl;
    }
}

void inventory::disply()
{
    cout<<"item id is :"<<iid<<endl;
    cout<<"item name is :"<<name<<endl;
    cout<<"item price is :"<<price<<endl;
    cout<<"item stock is :"<<stock<<endl;
}

