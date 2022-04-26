# include<iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    int xcp = x;
    int p; 
    cin>>p;
    int i = 2;
    while(i<=p)
    {
        x*=xcp;
        i++;
    }
    cout<<x;
}
