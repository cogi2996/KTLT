#include<bits/stdc++.h>
using namespace std;
int a[100];
int k,n;
void xuat()
{
	for(int i = 0;i<k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void lietKeToHop()
{
	for(int i =0;i<k;i++)
		a[i] = i;
	xuat();
	int i = k-1;
	do
	{
		while(a[i]<=n-k+i)
		{
			a[i]++;
			for(int j= i+1;j<k;j++)
				a[j] = a[j-1] +1;
			xuat();
			i =-1;
		}
		i--;
	}while(i>=0);
		
}

int main()
{
	 cin>>n>>k;
	lietKeToHop();
}
