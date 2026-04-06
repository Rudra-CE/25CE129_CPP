#include<iostream>
using namespace std;

template<class T>
void display(T arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

template<class T>
T findMax(T arr[], int n)
{
    T max = arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

template<class T>
void reverseArray(T arr[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

template<class T>
void leaders(T arr[], int n)
{
    T temp[100];
    int k = 0;

    T max_from_right = arr[n-1];
    temp[k++] = max_from_right;

    for(int i=n-2; i>=0; i--)
    {
        if(arr[i] > max_from_right)
        {
            max_from_right = arr[i];
            temp[k++] = arr[i];
        }
    }

    cout<<"Leader elements: ";
    for(int i=k-1; i>=0; i--)
        cout<<temp[i]<<" ";

    cout<<endl;
}

int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    int iarr[] = {16, 17, 4, 3, 5, 2};
    float farr[] = {1.1, 5.5, 2.2, 9.9, 3.3};
    char carr[] = {'a', 'z', 'b', 'y', 'c'};

    int n1 = 6, n2 = 5, n3 = 5;

    cout<<"--- INTEGER ARRAY ---\n";
    display(iarr, n1);

    cout<<"Max: "<<findMax(iarr, n1)<<endl;

    leaders(iarr, n1);

    reverseArray(iarr, n1);
    cout<<"Reversed: ";
    display(iarr, n1);


    cout<<"\n--- FLOAT ARRAY ---\n";
    display(farr, n2);

    cout<<"Max: "<<findMax(farr, n2)<<endl;

    leaders(farr, n2);

    reverseArray(farr, n2);
    cout<<"Reversed: ";
    display(farr, n2);


    cout<<"\n--- CHAR ARRAY ---\n";
    display(carr, n3);

    cout<<"Max: "<<findMax(carr, n3)<<endl;

    leaders(carr, n3);

    reverseArray(carr, n3);
    cout<<"Reversed: ";
    display(carr, n3);

    return 0;
}

