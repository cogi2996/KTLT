#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

void nhap(int *a,int &n)
{
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
}

int checkPrime(int x)
{
	if(x<2)
		return 0;
	for(int i = 2;i<=sqrt(x);i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

int MinPrimes(int *a,int n)
{
	int i = 0;
	while(i<n&&checkPrime(a[i])==0)
	{
		i++;
	}
	if(i==n)
		return 0;
	return a[i];	
}

int main()
{
	int a[100],n;
	nhap(a,n);
	sort(a,a+n);
	if(MinPrimes(a,n))
		cout<<MinPrimes(a,n);
	else
		cout<<"Khong ton tai so nguyen to trong day";
}
