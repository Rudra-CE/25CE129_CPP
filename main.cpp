#include<iostream>
#include<string>
#include"inventory.h"
using namespace std;
int main()
{
    int n,i,ch,id;

    cout<<"enter total number of item you want to add in system :";
    cin>>n;

    inventory item[100];

    for(i=0;i<n;i++)
    {
        int iid;
        string name;
        int price;
        int stock;

        cout<<"enter item id :";
        cin>>iid;

        cout<<"enter name of item :";
        cin>>name;

        cout<<"enter price of the item :";
        cin>>price;

        cout<<"enter stock of the item :";
        cin>>stock;

        item[i]=inventory(iid,name,price,stock);
    }

option:

    cout<<"\nenter 1. to add stock"<<endl;
    cout<<"enter 2. to sell item"<<endl;
    cout<<"enter 3. to disply all item"<<endl;
    cout<<"enter 4. to exit"<<endl;
    cout<<"enter choice :";
    cin>>ch;

    switch(ch)
    {
    case 1:
        cout<<"enter item id :";
        cin>>id;

        for(i=0;i<n;i++)
        {
            if(item[i].getid()==id)
            {
                item[i].add();
                break;
            }
        }
         if(i==n)
        {
            cout<<"item not found.."<<endl;
        }
        goto option;

    case 2:
        cout<<"enter item id :";
        cin>>id;

        for(i=0;i<n;i++)
        {
            if(item[i].getid()==id)
            {
                item[i].sold();
                break;
            }
        }
        if(i==n)
        {
            cout<<"item not found.."<<endl;
        }
        goto option;

    case 3:
        for(i=0;i<n;i++)
        {
            cout<<"\nitem :"<<i+1<<endl;
            item[i].disply();
        }
        goto option;

    case 4:
        cout<<"thank you..for using this system.."<<endl;
        break;

    default:
        cout<<"invalid choice .. please enter valid choice .."<<endl;
        goto option;
    }

    return 0;
}

