#include<iostream>
using namespace std;

int nhap(int &n,int a[])
{
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
}

int sum(int *a,int n)
{
	if(n==1)
		return a[0];
	else
	{
		return a[n-1] + sum(a,n-1);
	}
}

int main()
{
	int n,a[100];
	nhap(n,a);
	cout<<sum(a,n);
}
