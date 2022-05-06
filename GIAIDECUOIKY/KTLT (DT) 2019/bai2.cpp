#include<bits/stdc++.h>
using namespace std;
int arr[25],a[25];
int n,k;
int Max = -90000;
void duyetCH()
{
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		if(a[i] == 1)
			sum += arr[i];
	}
	if(sum > Max && sum%k==0)
	{
		Max = sum;
	}
}

void hoanvi(int size)
{
	if(size==n)
		duyetCH();
	else
	{
		for(int i =0;i<=1;i++)
		{
			a[size] = i;
			hoanvi(size+1);
		}
	}
}	

int main() {
	cin>>n>>k;
	for(int  i =0;i<n;i++)
		cin>>arr[i];
	hoanvi(0);
	cout<<Max;
	return 0;
}

