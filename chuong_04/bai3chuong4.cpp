#include<iostream>
using namespace std;

int giaoThua(int n)
{
	if(n ==  1)
		return 1;
	else
		return n*giaoThua(n-1);
}

int main()
{
int n;
cin>>n;
cout<<giaoThua(n);	
}
