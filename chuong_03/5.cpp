#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double s = 0;
    long long temp = 1;
    for(int i = 1;i<=n;i++)
    {   
        s = s + 1/(double)(temp = temp * i);
        
    cout<<"("<< 1/(double)(temp = temp * i)<<")";
    }
    cout<<s;
}