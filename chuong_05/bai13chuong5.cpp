#include<bits/stdc++.h>
using namespace std;
int a[100];
int n,k;

void xuat()
{
	for(int i =0;i<k;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void sinhToHop()
{
	for(int i =0;i<k;i++)
		a[i] = i;
	xuat();
	int i = k-1;
	while(i>=0)
	{
		if(a[i]<=n-k+i)
		{
			a[i]++;
			for(int j = i+1;i<k;i++)
				a[j] = a[j-1] +1;
			xuat();
			i = k-1;
		}
		i--;
	}
}

int main()
{
	cin>>n;
	for(int i =0;i<n;i++)
	{
		k=i;
		sinhToHop();		
	}
}
