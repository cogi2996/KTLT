#include<bits/stdc++.h>
using namespace std;
int a[100];
int n;
void xuat()
{
	for(int i =0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void latNguoc(int x,int y)
{
	while(x<y)
	{
		swap(a[x++],a[y--]);
	}
}

void sinhHoanVi(int n)
{
	for(int i =0;i<n;i++)
	{
		a[i] = i;
	}
	xuat();
	do
	{
		int k = n-2;
		while(a[k]>a[k+1]&&k>=0)
			k--;
		if(k<0)
			break;
		int l = n-1;
		while(a[l]<a[k])
			l--;
		swap(a[l],a[k]);
		latNguoc(k+1,n-1);
		xuat();
	}while(true);
}

int main()
{
	cin>>n;
	sinhHoanVi(n);
}
