#include<iostream>
#include<math.h>
using namespace std;

void tongDenX (long long &s,long long x,long long &i)
{
    while(i<x)
    {
        s  = s + pow(10,i);
        i++;
    }
}

int main()
{
    int n;
    cin>>n;
    long long s =0,x = 1,i = 0;
    while(1)
    {
        tongDenX(s,x,i);
        if((s*x)%n == 0 && (s*x)/n > 0)
        {
            cout<<x;
            break;
        } 
        x++;

    }
}