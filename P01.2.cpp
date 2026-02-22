#include<iostream>
#include<string.h>
using namespace std;
class library
{
private :
    int book_id;
    string title;
    string author;
    int num_copie;

public :
    int search(int);
    void set_data();
    void add_b();
    void issue_b();
    void return_b();
    void display_b();
};
int library::search(int bookid)
{
    if(bookid==book_id)
        return 1;
    else
        return 0;
}

void library::set_data()
{
    cout<<"enter book id :";
    cin>>book_id;
    cout<<"enter book title :";
    cin.ignore();
    getline(cin,title);
    cout<<"enter author name :";
    cin.ignore();
    cin.ignore();
    cin.ignore();
    cin.ignore();
    getline(cin,author);
    cout<<"enter total number of book :";
    cin>>num_copie;
    cout<<endl;
}
void library::add_b()
{
    int ncopie=0;
    cout<<"enter book number for update total count :";
    cin>>ncopie;
    cout<<endl;
    num_copie=ncopie+num_copie;

}
void library::issue_b()
{
    int b;
    cout<<"enter number of copies you want to issue :";
    cin>>b;
    if(num_copie>=b)
    {
        num_copie=num_copie-b;
        cout<<"book issued"<<endl;
    }
    else
    {
        cout<<"insufficient books"<<endl;
        cout<<"enter choice again"<<endl;
    }
}
void library::return_b()
{
    num_copie++;
    cout<<"book returned"<<endl;

}
void library::display_b()
{

    cout<<"book id :"<<book_id<<endl;
    cout<<"book title :"<<title<<endl;
    cout<<"author name :"<<author<<endl;
    cout<<"available total number of books :"<<num_copie<<endl;
}

int main()
{
    library b[50];
    int book_id;
    int i,ch;
    int j=0;
    int flag=0;
    cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
option:

    cout<<"enter 1.  add new book details."<<endl;
    cout<<"enter 2.  only add book."<<endl;
    cout<<"enter 3.  issue book."<<endl;
    cout<<"enter 4.  return book."<<endl;
    cout<<"enter 5.  to show available book."<<endl;
    cout<<"enter 6.  exit."<<endl;
    cout<<"enter choice :";
    cin>>ch;
    cout<<endl;

    switch(ch)
    {
    case 1:
        b[j].set_data();
        j++;
        flag=1;
        goto option;
    case 2:
        cout<<"enter book id :";
        cin>>book_id;

        for(i=0; i<j; i++)
        {
            if(b[i].search(book_id))
            {
                b[i].add_b();
                flag=1;
                break;
            }
        }

        if(!flag)
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }
        goto option;
    case 3:
        cout<<"enter book id :";
        cin>>book_id;



        for(i=0; i<j; i++)
        {
            if(b[i].search(book_id))
            {
                b[i].issue_b();
                flag=1;
                break;
            }
        }

        if(!flag)
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }

        goto option;
    case 4:
        cout<<"enter book id :";
        cin>>book_id;

        for(i=0; i<j; i++)
        {
            if(b[i].search(book_id))
            {
                b[i].return_b();
                flag=1;
                break;
            }
        }

        if(!flag)
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }
        goto option;
    case 5:
        if(flag==0)
        {
            cout<<"there is no book available in libery.. \nfirst enter book in libery. \nenter choice again."<<endl;
            cout<<endl;
        }
        if(flag==1)
        {
            cout<<"---------------------------availablebooks---------------------------"<<endl;
        }
        for(i=0; i<j; i++)
        {
            if(j!=0)
            {
                b[i].display_b();
            }

        }

        goto option;
    /*    cout<<"enter book id :";
        cin>>book_id;

        for(i=0; i<j; i++)
        {
            if(b[i].search(book_id))
                b[i].display_b();
            flag=1;
            break;
            {
            }
        }

        if(!flag)
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }
        goto option;
        */
    case 6:
        cout<<"thank you ... visite again.."<<endl;
        return 0;
    default:
        cout<<"invalid choice .. enter your choice again.."<<endl;
        goto option;
    }
cout<<"visit again..";
}
