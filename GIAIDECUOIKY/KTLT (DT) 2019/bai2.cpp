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

void toHop(int size)
{
	if(size==n)
		duyetCH();
	else
	{
		for(int i =0;i<=1;i++)
		{
			a[size] = i;
			toHop(size+1);
		}
	}
}	

int main() {
	cin>>n>>k;
	for(int  i =0;i<n;i++)
		cin>>arr[i];
	toHop(0);
	cout<<Max;
	return 0;
}

