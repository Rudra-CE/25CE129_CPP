#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

int recursive(int a[], int n);

int main()
{
     cout<<"NAME       : Rudra Vaghasiya\n";
    cout<<"ID         : 25CE129\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[2000];

 /*   for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>a[i];
    }
   */
    for(int i=0;i<n;i++)
    {
        a[i]=a[i]+1000;
  //  cout<<"Enter element "<<i+1<<" : ";

    }

    cout<<fixed<<setprecision(10);

    // -------- Iterative --------
    auto start1 = high_resolution_clock::now();

    int sum1=0;
    for(int k=0;k<100000;k++)   // repeat many times
    {
        sum1=0;
        for(int i=0;i<n;i++)
        {
            sum1+=a[i];
        }
    }

    auto end1 = high_resolution_clock::now();

    double time_iterative =
    duration<double>(end1-start1).count();


    // -------- Recursive --------
    auto start2 = high_resolution_clock::now();

    int sum2=0;
    for(int k=0;k<100000;k++)   // repeat many times
    {
        sum2 = recursive(a,n);
    }

    auto end2 = high_resolution_clock::now();

    double time_recursive =
    duration<double>(end2-start2).count();


    cout<<"\nIterative Sum = "<<sum1<<endl;
    cout<<"Iterative Time = "<<time_iterative<<" seconds"<<endl;

    cout<<"\nRecursive Sum = "<<sum2<<endl;
    cout<<"Recursive Time = "<<time_recursive<<" seconds"<<endl;

    return 0;
}

int recursive(int a[], int n)
{
    if(n==0)
        return 0;

    return a[n-1] + recursive(a,n-1);
}
