#include<iostream>
using namespace std;
int a[100];
int n;
void lietKe(int k);
void xuat();
int main()
{
	cin>>n;
	lietKe(0);
}

void xuat()
{
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void lietKe (int k)
{
	if(k == n)
	{
		xuat(); 	
	}
	else
	{
		for(int i = 0;i<=1;i++)
		{
			a[k] = i;
			lietKe(k+1);
		}
	}
}

