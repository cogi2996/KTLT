#include<iostream>
using namespace std;

void nhap(int &n,int *a)
{
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
}

int main()
{
	int n;
	int a[1000];
	nhap(n,a);
	int maxSum = 0;
	for(int i = 0;i<n;i++)
	{
		int sum = 0;
		for(int j = i;j<n;j++)
		{
			sum+=a[j];
			if(sum>maxSum)
				maxSum = sum;
		}
	}
	cout<<maxSum;
}
