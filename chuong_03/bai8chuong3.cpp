#include<iostream>
using namespace std;
int main()
{
    double s = 0;
    // long long i = 1;                                             
    double a;
    cin>>a;
    long long i = 1;
    for(;s<=a;i++)
    {
        s = s + (double)1/i;
    }
    cout<<--i;
}