#include<iostream>
using namespace std;
class shape
{
    protected :
    float radius;
public :
    void input();
    void display();

};
void shape::input()
{
    cout<<"enter radius :";
    cin>>radius;
}
void shape::display()
{
    cout<<"circle radius is :"<<radius<<endl;
}
class circle : public shape
{
    float area;
public :
    void carea();
};
void circle::carea()
{
    area=(3.14)*radius*radius;
    cout<<"circle area is :"<<area<<endl;
}
int main()
{
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    circle c[50];
    int n,i;
    cout<<"enter number of circle you want to add :";
    cin>>n;
    cout<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"circle :"<<i+1<<endl;
        c[i].input();
        c[i].display();
        c[i].carea();
        cout<<endl;
    }
    return 0;

}
