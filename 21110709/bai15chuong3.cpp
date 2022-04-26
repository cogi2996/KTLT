#include<iostream>
using namespace std;

void nhap(int &x,int &n,int *a)
{
    cout<<"Nhap n: ";
    cin>>n;
    cout<<"Nhap X: ";
    cin>>x;
    cout<<endl;
    cout<<"Nhap cac so hang: ";
    for(int i = 0 ;i<n;i++)
        cin>>a[i];
}

void solve(int x,int n,int *a)
{
    int s = a[0];
    for(int i = 1;i<n;i++)
    {
        s = s + a[i]*x*(a[i-1]/)
    }
}

int main()
{
    int n;
    int x;
    int a[100];
    nhap(x,n,a);
    solve(x,n,a);
}