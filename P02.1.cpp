#include<iostream>
#include<string>
using namespace std;
class rectangle
{
    int rnum;
    int l;
    int b;
public:
    void area();
    void perimeter();
    void update_data();
    void display_data();
    void set_data();
    bool search(int id);

};
void rectangle::area()
{

    cout<<"the area of rectangle is :"<<l*b<<endl;
}
void rectangle::perimeter()
{

    cout<<"the perimeter of rectangle is :"<<2*(l+b)<<endl;

}
void rectangle::update_data()
{
    cout<<"enter new length of rectangle :";
    cin>>l;
    cout<<"enter new breath of rectangle :";
    cin>>b;
}
void rectangle::display_data()
{
    cout<<"length of rectangle is :"<<l<<endl;
    cout<<"breath of rectangle is :"<<b<<endl;
    cout<<"the area of rectangle is :"<<(l*b)<<endl;
    cout<<"the perimeter of rectangle is :"<<2*(l+b)<<endl;


}
void rectangle::set_data()
{
    cout<<"enter rectangle number :";
    cin>>rnum;

    cout<<"enter length of rectangle :";
    cin>>l;
    cout<<"enter breath of rectangle :";
    cin>>b;

}
bool rectangle::search(int id)

{
    return id==rnum;
}


int main()
{
    int rnum;
    int t=0;
    int i;
    int ch;
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    rectangle r[50];
option:

    cout<<"enter 1.  to add new rectangle ."<<endl;
    cout<<"enter 2.  calculating area."<<endl;
    cout<<"enter 3.  calculating perimeter."<<endl;
    cout<<"enter 4.  update lenghth and breath."<<endl;
    cout<<"enter 5.  to show all rectangle data."<<endl;
    cout<<"enter 6.  exit."<<endl;
    cout<<"enter choice :";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
    case 1:

        r[t].set_data();
        t++;
        goto option;
    case 2:
        cout<<"enter rectangle number :";
        cin>>rnum;
        for(i=0; i<t; i++)
        {
            if(r[i].search(rnum))
            {
                r[i].area();
                break;
            }
        }
        if(i==t)
        {
            cout<<"rectangle not found.."<<endl;
        }

        goto option;


    case 3:
        cout<<"enter rectangle number :";
        cin>>rnum;
        for(i=0; i<t; i++)
        {
            if(r[i].search(rnum))
            {
                r[i].perimeter();
                break;
            }
        }
        if(i==t)
        {
            cout<<"rectangle not found.."<<endl;
        }

        goto option;
    case 4:
        cout<<"enter rectangle number :";
        cin>>rnum;

         for(i=0; i<t; i++)
        {
            if(r[i].search(rnum))
            {
                r[i].update_data();
                break;
            }
        }
        if(i==t)
        {
            cout<<"rectangle not found.."<<endl;
        }

        goto option;
    case 5:
 if(t==0)
            {
              cout<<"syatem has no rectangle to display:"<<endl;
            }
        for(i=0; i<t ; i++)
        {
cout<<"recangle :"<<i+1<<endl;

            r[i].display_data();
        }
        goto option;
    case 6:
        break;

    default:
        cout<<"invalid choice .. enter your choice again.."<<endl;
        goto option;

    }



    return 0;

}
