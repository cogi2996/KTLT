#include<iostream>
using namespace std;
int  main()
{
    int f1 = 1;
    int f2 = 1;
    int  n ;
    cin>>n;
    int fn = 0;
    for(int i = 3;i<=n;i++)
    {
        fn = f1 + f2;
        f1  = f2;
        f2  = fn;
    }
        cout<<fn;
}