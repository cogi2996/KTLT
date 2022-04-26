#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

void nhap(int a[],int &n)
{
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
			a[i] = -a[i];
	}
}

bool balance(int *a,int n)
{
	return a[0] == a[n-1];
}

int UCLN(int a[],int n)
{
	sort(a,a+n);
	while(!balance(a,n))
	{
		for(int i = 1;i<n;i++)
		{
			if(a[i]!=a[0])
			{
				a[i] = a[i] - a[0];
			}
		}
			sort(a,a+n);
	}
	return a[0];
}

int main()
{
int n,a[100];
nhap(a,n);	
cout<<UCLN(a,n);
}
