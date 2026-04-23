#include<iostream>
using namespace std;
int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    int n,i;
    int ch;
    int *arry=new int[n];
    cout<<"enter number you want to enter first in system :";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"enter "<<i+1<<" element :";
        cin>>arry[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<i+1<<" element is :"<<arry[i]<<endl;

    }
    while(ch!=4)
    {


        cout<<"1. enter another number at last."<<endl;
        cout<<"2. for deleat number from any location."<<endl;
        cout<<"3. display the current arry content."<<endl;
        cout<<"4. exit the system."<<endl;
        cout<<"enter choice from above :";
        cin>>ch;



        switch(ch)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:

            cout<<"exit system .";
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;

        }
    }
    return 0;
}
