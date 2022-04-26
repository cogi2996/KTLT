#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double s = 1;
    for(int i = 1;i<=n;i++)
    {
        s = s*(1 + (double)1/(i*i));
    }
    cout<<s;
}