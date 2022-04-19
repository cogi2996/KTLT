#include<iostream>
using namespace std;

int toHop(int n,int k)
{
	if(n == k||k==0)
		return 1;
	return toHop(n-1,k) + toHop(n-1,k-1);
	
}

int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	cout<<toHop(n,k);
	return 0;
}
