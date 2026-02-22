#include<iostream>
#include<string>
using namespace std;
class student
{
    int rollnum;
    string name;
    int m1;
    int m2;
    int m3;
    int ave=0;

public :
  /*  student()
    {
        rollnum;
        name;
        m1;
        m2;
        m3;

    }
    Student(int r,string n,float marks1,float marks2,float marks3)
    {

        rollnum=r;
        name=n;
        m1=marks1;
        m2=marks2;
        m3=marks3;
    }
     void ave_marks()
    {
        cout<<"roll number :"<<rollnum<<endl;
        cout<<"Student : "<<name<<endl;
        cout<<"Average Marks : "<<(m1+m2+m3)/3<<endl;

    }
    */
    void displaydata();
    void enterdata();

};
void student::displaydata()
{
    cout<<"student roll number is :"<<rollnum<<endl;
    cout<<"student name is :"<<name<<endl;
    cout<<"student  1st marks is :"<<m1<<endl;
    cout<<"student  2nd marks is :"<<m2<<endl;
    cout<<"student  3rd marks is :"<<m3<<endl;
    cout<<"student average for three marks is :"<<ave<<endl;


}
void student::enterdata()
{
    cout<<"enter student roll number :";
    cin>>rollnum;
    cout<<"enter student name :";
   cin.ignore();
    getline(cin,name);
    cout<<"enter student  1st marks  :";
    cin>>m1;
    cout<<"enter student  2nd marks  :";
    cin>>m2;
    cout<<"enter student  3rd marks  :";
    cin>>m3;
    ave=(m1+m2+m3)/3;

}
int main()
{
   /* Student s1;
    Student s2(129,"rudra",95,87,90);
    s1.ave_marks();
    s2.ave_marks();
     */
     student s[50];

    int ch,n,i;
    int f=0;
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
option :
    cout<<"enter 1.adding student data"<<endl;
    cout<<"enter 2.desply all student data"<<endl;
    cout<<"enter choice :";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
    case 1:
cout<<"enter number of student you want to add data :";
        cin>>n;
        for(i=0; i<n; i++)
        {
            cout<<"for student "<<i+1<<"\n";
            s[i].enterdata();
        }
        f=1;
          if(i==n)
          {
              cout<<"student data added....\n";
              cout<<endl;
          }
        goto option;



    case 2:
        if(f==1)
        {
            cout<<"-------------------------student details-----------------------------------\n";
                        for(i=0; i<n; i++)
            {

                cout<<"for student "<<i+1<<endl;
                s[i].displaydata();
            }
            break ;
        }
        else
        {
            cout<<"first enter student data \n"<<endl;
            goto option;
        }

    default :
        cout<<"invalid choice.. \n enter choice again\n"<<endl;
        goto option;
    }

    return 0;
}
