#include<iostream>
using namespace std;

int fiBo(int n)
{
	if(n==0)
		return 0;	
	if(n==1)
		return 1;
	return fiBo(n -1)+fiBo(n-2);
}

int main()
{
	int n;	
	cin>>n;
	cout<<fiBo(n);
	return 0;
}
